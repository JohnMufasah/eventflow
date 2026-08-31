/**
 * @file EventNotificationHandler.cpp
 * @brief Implements the ConcreteObserver for EventFlow notifications.
 */

#include "EventNotificationHandler.h"

#include "EventNotice.h"
#include "../composite/EventComponent.h"

/**
 * @brief Constructs an EventNotificationHandler.
 *
 * The handler stores a pointer to the EventComponent that should
 * receive notifications.
 *
 * @param target EventComponent that will receive the notification.
 */
EventNotificationHandler::EventNotificationHandler(EventComponent* target)
    : target(target)
{
}

/**
 * @brief Processes a pushed EventNotice.
 *
 * The notification is forwarded to the target EventComponent,
 * allowing the Composite structure to handle and propagate it.
 *
 * @param notice Notification received from the Subject.
 */
void EventNotificationHandler::update(EventNotice* notice)
{
    if (notice == nullptr)
    {
        return;
    }

    if (target != nullptr)
    {
        target->handleNotice(notice);
    }
}

/**
 * @brief Gets the target EventComponent.
 *
 * @return Pointer to the EventComponent receiving notifications.
 */
EventComponent* EventNotificationHandler::getTarget() const
{
    return target;
}