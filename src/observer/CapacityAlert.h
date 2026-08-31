#ifndef CAPACITYALERT_H
#define CAPACITYALERT_H

#include "EventNotice.h"

/**
 * @brief Notice generated when an event zone reaches capacity.
 */
class CapacityAlert : public EventNotice
{
private:
    bool laboratoryZone;

public:
    /**
     * @brief Creates a capacity alert.
     *
     * @param message Description of the capacity issue.
     * @param location Zone that reached capacity.
     * @param laboratoryZone Whether the affected zone is a laboratory.
     */
    CapacityAlert(
        const std::string& message,
        const std::string& location,
        bool laboratoryZone = false);

    /**
     * @brief Returns the notice type.
     */
    std::string getType() const override;

    /**
     * @brief Applies the capacity response to a component.
     *
     * @param component Component receiving the alert.
     */
    void affect(EventComponent* component) override;

    /**
     * @brief Indicates whether the alert came from a laboratory zone.
     */
    bool isLaboratoryZone() const;
};

#endif