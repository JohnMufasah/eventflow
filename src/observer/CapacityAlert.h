/**
 * @file CapacityAlert.h
 * @brief Defines capacity alert notifications for the EventFlow system.
 */

#ifndef CAPACITYALERT_H
#define CAPACITYALERT_H

#include "EventNotice.h"

/**
 * @class CapacityAlert
 * @brief Represents a notification that an event zone has reached capacity.
 *
 * A CapacityAlert is pushed through the Observer system when a zone
 * reaches its capacity limit. The receiving EventComponent determines
 * how it reacts to the alert.
 */
class CapacityAlert : public EventNotice
{
public:

    /**
     * @brief Constructs a capacity alert.
     *
     * @param message Description of the capacity condition.
     * @param location Location of the affected zone.
     */
    CapacityAlert(const std::string& message,
                  const std::string& location);

    /**
     * @brief Returns the notification type.
     *
     * @return "Capacity Alert".
     */
    std::string getType() const override;

    /**
     * @brief Applies the capacity alert to an EventComponent.
     *
     * @param component Component receiving the alert.
     */
    void affect(EventComponent* component) override;
};

#endif