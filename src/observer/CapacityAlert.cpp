#include "CapacityAlert.h"
#include "../composite/EventComponent.h"

CapacityAlert::CapacityAlert(
    const std::string& message,
    const std::string& location,
    bool laboratoryZone)
    : EventNotice(message, location),
      laboratoryZone(laboratoryZone)
{
}

std::string CapacityAlert::getType() const
{
    return "Capacity Alert";
}

void CapacityAlert::affect(EventComponent* component)
{
    if (component != nullptr)
    {
        component->onCapacityAlert();
    }
}

bool CapacityAlert::isLaboratoryZone() const
{
    return laboratoryZone;
}