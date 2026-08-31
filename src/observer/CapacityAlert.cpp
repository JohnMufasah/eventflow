/**
 * @file CapacityAlert.cpp
 * @brief Implements capacity alert notifications.
 */

#include "CapacityAlert.h"
#include "../composite/EventComponent.h"

/**
 * @brief Constructs a CapacityAlert.
 *
 * @param message Description of the capacity condition.
 * @param location Location of the affected event zone.
 */
CapacityAlert::CapacityAlert(const std::string& message,
                             const std::string& location)
    : EventNotice(message, location)
{
}

/**
 * @brief Returns the notification type.
 *
 * @return "Capacity Alert".
 */
std::string CapacityAlert::getType() const
{
    return "Capacity Alert";
}

/**
 * @brief Applies a capacity alert to an EventComponent.
 *
 * Delegates the response to the receiving component's
 * onCapacityAlert() handler.
 *
 * @param component Component receiving the alert.
 */
void CapacityAlert::affect(EventComponent* component)
{
    if (component != nullptr)
    {
        component->onCapacityAlert();
    }
}