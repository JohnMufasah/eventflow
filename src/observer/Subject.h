/**
 * @file Subject.h
 * @brief Defines the Subject interface for the EventFlow Observer pattern.
 */

#ifndef SUBJECT_H
#define SUBJECT_H

class Observer;
class EventNotice;

/**
 * @class Subject
 * @brief Interface for objects that manage and notify Observers.
 *
 * A Subject maintains a collection of registered Observers.
 * Observers can attach to or detach from the Subject.
 *
 * When a change occurs, the Subject uses notify() to push an
 * EventNotice to all registered Observers.
 */
class Subject
{
public:

    /**
     * @brief Registers an Observer with the Subject.
     *
     * @param observer Pointer to the Observer that should receive
     *                 future notifications.
     */
    virtual void attach(Observer* observer) = 0;

    /**
     * @brief Removes an Observer from the Subject.
     *
     * @param observer Pointer to the Observer that should no longer
     *                 receive notifications.
     */
    virtual void detach(Observer* observer) = 0;

    /**
     * @brief Notifies all registered Observers.
     *
     * The EventNotice is pushed directly to each registered Observer.
     *
     * @param notice Pointer to the EventNotice being pushed.
     */
    virtual void notify(EventNotice* notice) = 0;

    /**
     * @brief Virtual destructor for the Subject interface.
     */
    virtual ~Subject() = default;
};

#endif