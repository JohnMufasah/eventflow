#include "EventNotificationHandler.h"

#include "EventNotice.h"
#include "../composite/EventComponent.h"

EventNotificationHandler::EventNotificationHandler(EventComponent* target)
    : target(target)
{
}

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

EventComponent* EventNotificationHandler::getTarget() const
{
    return target;
}