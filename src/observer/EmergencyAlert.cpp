/**
 * @file EmergencyAlert.cpp
 * @brief Implements emergency alert notifications.
 */

#include "EmergencyAlert.h"
#include "../composite/EventComponent.h"

/**
 * @brief Constructs an EmergencyAlert.
 *
 * @param message Description of the emergency.
 * @param location Location associated with the emergency.
 */
EmergencyAlert::EmergencyAlert(const std::string& message,
                               const std::string& location)
    : EventNotice(message, location)
{
}

/**
 * @brief Returns the notification type.
 *
 * @return "Emergency Alert".
 */
std::string EmergencyAlert::getType() const
{
    return "Emergency Alert";
}

/**
 * @brief Applies an emergency alert to an EventComponent.
 *
 * The receiving component determines its own response through
 * its onEmergencyAlert() implementation.
 *
 * @param component Component receiving the emergency alert.
 */
void EmergencyAlert::affect(EventComponent* component)
{
    if (component != nullptr)
    {
        component->onEmergencyAlert();
    }
}