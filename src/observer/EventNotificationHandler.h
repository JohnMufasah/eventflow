/**
 * @file EventNotificationHandler.h
 * @brief Defines the ConcreteObserver for the EventFlow notification system.
 */

#ifndef EVENTNOTIFICATIONHANDLER_H
#define EVENTNOTIFICATIONHANDLER_H

#include "Observer.h"

class EventNotice;
class EventComponent;

/**
 * @class EventNotificationHandler
 * @brief Concrete Observer that processes EventFlow notifications.
 *
 * EventNotificationHandler receives EventNotice objects pushed by
 * EventControl and forwards them to its target EventComponent.
 *
 * The target is responsible for handling the notification within
 * the Composite structure.
 */
class EventNotificationHandler : public Observer
{
private:

    /// EventComponent affected by the notification.
    EventComponent* target;

public:

    /**
     * @brief Constructs an EventNotificationHandler.
     *
     * @param target EventComponent that should receive the notification.
     */
    EventNotificationHandler(EventComponent* target);

    /**
     * @brief Processes a pushed EventNotice.
     *
     * The notice is forwarded to the target EventComponent.
     *
     * @param notice EventNotice received from the Subject.
     */
    void update(EventNotice* notice) override;

    /**
     * @brief Gets the target EventComponent.
     *
     * @return Pointer to the target EventComponent.
     */
    EventComponent* getTarget() const;
};

#endif