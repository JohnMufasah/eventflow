/**
 * @file EmergencyAlert.h
 * @brief Defines emergency alert notifications for the EventFlow system.
 */

#ifndef EMERGENCYALERT_H
#define EMERGENCYALERT_H

#include "EventNotice.h"

/**
 * @class EmergencyAlert
 * @brief Represents an emergency notification sent through EventFlow.
 *
 * The same EmergencyAlert can produce different reactions depending
 * on the EventComponent receiving it.
 */
class EmergencyAlert : public EventNotice
{
public:

    /**
     * @brief Constructs an emergency alert.
     *
     * @param message Description of the emergency.
     * @param location Location associated with the emergency.
     */
    EmergencyAlert(const std::string& message,
                   const std::string& location);

    /**
     * @brief Returns the notification type.
     *
     * @return "Emergency Alert".
     */
    std::string getType() const override;

    /**
     * @brief Applies the emergency alert to an EventComponent.
     *
     * The receiving component handles the alert according to
     * its concrete implementation.
     *
     * @param component Component receiving the alert.
     */
    void affect(EventComponent* component) override;
};

#endif