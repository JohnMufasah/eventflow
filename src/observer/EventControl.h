/**
 * @file EventControl.h
 * @brief Defines the ConcreteSubject for the EventFlow Observer pattern.
 */

#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include <vector>

#include "Subject.h"

class Observer;
class EventNotice;

/**
 * @class EventControl
 * @brief Concrete Subject responsible for managing event notifications.
 *
 * EventControl maintains a collection of registered Observers.
 * When an event change occurs, notify() pushes an EventNotice
 * to every registered Observer.
 */
class EventControl : public Subject
{
private:

    /// Collection of Observers registered with this Subject.
    std::vector<Observer*> observers;

public:

    /**
     * @brief Registers an Observer.
     *
     * @param observer Observer to register.
     */
    void attach(Observer* observer) override;

    /**
     * @brief Removes an Observer.
     *
     * @param observer Observer to remove.
     */
    void detach(Observer* observer) override;

    /**
     * @brief Pushes a notification to all registered Observers.
     *
     * @param notice EventNotice containing the event change.
     */
    void notify(EventNotice* notice) override;
};

#endif