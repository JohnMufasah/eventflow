/**
 * @file Observer.h
 * @brief Defines the Observer interface for the EventFlow notification system.
 */

#ifndef OBSERVER_H
#define OBSERVER_H

class EventNotice;

/**
 * @class Observer
 * @brief Interface for objects that receive event notifications.
 *
 * Classes that implement Observer can register with a Subject and
 * receive notifications when an event-related change occurs.
 *
 * The Observer uses the Push notification approach, meaning that
 * the EventNotice is passed directly to update().
 */
class Observer
{
public:

    /**
     * @brief Handles a notification received from a Subject.
     *
     * @param notice The event notification containing information
     *               about the change.
     */
    virtual void update(EventNotice* notice) = 0;

    /**
     * @brief Virtual destructor for the Observer interface.
     */
    virtual ~Observer() = default;
};

#endif