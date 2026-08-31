#ifndef EVENTNOTIFICATIONHANDLER_H
#define EVENTNOTIFICATIONHANDLER_H

#include "Observer.h"

class EventNotice;
class EventComponent;

/**
 * @brief Observer that forwards notices to an EventComponent.
 */
class EventNotificationHandler : public Observer
{
private:
    EventComponent* target;

public:
    /**
     * @brief Creates a notification handler.
     *
     * @param target Component that receives forwarded notices.
     */
    explicit EventNotificationHandler(EventComponent* target);

    /**
     * @brief Receives a pushed EventNotice.
     *
     * @param notice Notice being received.
     */
    void update(EventNotice* notice) override;

    /**
     * @brief Returns the current target.
     */
    EventComponent* getTarget() const;

    /**
     * @brief Changes the target component.
     *
     * @param newTarget New component to receive notices.
     */
    void setTarget(EventComponent* newTarget);
};

#endif