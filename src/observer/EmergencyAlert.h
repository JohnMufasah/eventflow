#ifndef EMERGENCYALERT_H
#define EMERGENCYALERT_H

#include "EventNotice.h"

/**
 * @brief Notice used to report an emergency situation.
 */
class EmergencyAlert : public EventNotice
{
public:
    /**
     * @brief Creates an emergency alert.
     *
     * @param message Description of the emergency.
     * @param location Location affected by the emergency.
     */
    EmergencyAlert(
        const std::string& message,
        const std::string& location);

    /**
     * @brief Returns the notice type.
     */
    std::string getType() const override;

    /**
     * @brief Applies the emergency response to a component.
     *
     * @param component Component receiving the alert.
     */
    void affect(EventComponent* component) override;
};

#endif