/**
 * @file EventControl.cpp
 * @brief Implements the EventControl subject.
 */

#include "EventControl.h"
#include "Observer.h"
#include "EventNotice.h"

#include <algorithm>

void EventControl::attach(Observer* observer)
{
    if (observer == nullptr)
    {
        return;
    }

    if (std::find(
            observers.begin(),
            observers.end(),
            observer) == observers.end())
    {
        observers.push_back(observer);
    }
}

void EventControl::detach(Observer* observer)
{
    auto it = std::find(
        observers.begin(),
        observers.end(),
        observer);

    if (it != observers.end())
    {
        observers.erase(it);
    }
}

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