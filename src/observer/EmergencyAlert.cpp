#include "EmergencyAlert.h"
#include "../composite/EventComponent.h"

EmergencyAlert::EmergencyAlert(
    const std::string& message,
    const std::string& location)
    : EventNotice(message, location)
{
}

std::string EmergencyAlert::getType() const
{
    return "Emergency Alert";
}

void EmergencyAlert::affect(EventComponent* component)
{
    if (component != nullptr)
    {
        component->onEmergencyAlert();
    }
}