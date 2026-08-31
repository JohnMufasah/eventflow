#ifndef OBSERVER_H
#define OBSERVER_H

class EventNotice;

/**
 * @brief Observer interface for the EventFlow notification system.
 *
 * EventFlow uses the Push Observer approach, where the EventNotice
 * is passed directly to the observer.
 */
class Observer
{
public:
    /**
     * @brief Receives a notification.
     *
     * @param notice Notification being received.
     */
    virtual void update(EventNotice* notice) = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~Observer() = default;
};

#endif