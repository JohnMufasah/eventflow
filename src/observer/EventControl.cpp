/**
 * @file EventControl.cpp
 * @brief Implements the ConcreteSubject for the EventFlow Observer pattern.
 */

#include "EventControl.h"
#include "Observer.h"
#include "EventNotice.h"

#include <algorithm>

/**
 * @brief Registers an Observer with EventControl.
 *
 * Null pointers and duplicate registrations are ignored.
 *
 * @param observer Observer to register.
 */
void EventControl::attach(Observer* observer)
{
    if (observer == nullptr)
    {
        return;
    }

    if (std::find(observers.begin(), observers.end(), observer) == observers.end())
    {
        observers.push_back(observer);
    }
}

/**
 * @brief Removes an Observer from EventControl.
 *
 * If the Observer is not registered, no action is taken.
 *
 * @param observer Observer to remove.
 */
void EventControl::detach(Observer* observer)
{
    if (observer == nullptr)
    {
        return;
    }

    auto it = std::find(observers.begin(), observers.end(), observer);

    if (it != observers.end())
    {
        observers.erase(it);
    }
}

/**
 * @brief Pushes an EventNotice to all registered Observers.
 *
 * Each registered Observer receives the same EventNotice through
 * its update() method.
 *
 * @param notice Notification to push to the Observers.
 */
void EventControl::notify(EventNotice* notice)
{
    if (notice == nullptr)
    {
        return;
    }

    for (Observer* observer : observers)
    {
        if (observer != nullptr)
        {
            observer->update(notice);
        }
    }
}