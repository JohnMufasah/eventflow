#ifndef SUBJECT_H
#define SUBJECT_H

class Observer;
class EventNotice;

/**
 * @brief Subject interface used by the EventFlow Observer pattern.
 *
 * A Subject maintains a collection of Observers and notifies them
 * when an EventNotice is generated.
 */
class Subject
{
public:
    /**
     * @brief Registers an observer.
     *
     * @param observer Observer to attach.
     */
    virtual void attach(Observer* observer) = 0;

    /**
     * @brief Removes an observer.
     *
     * @param observer Observer to detach.
     */
    virtual void detach(Observer* observer) = 0;

    /**
     * @brief Sends a notification to attached observers.
     *
     * @param notice Notification to send.
     */
    virtual void notify(EventNotice* notice) = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~Subject() = default;
};

#endif