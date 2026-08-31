#include "AllergenAlert.h"
#include "../composite/EventComponent.h"

AllergenAlert::AllergenAlert(
    const std::string& message,
    const std::string& location,
    const std::string& dietaryTag)
    : EventNotice(message, location),
      dietaryTag(dietaryTag)
{
}

std::string AllergenAlert::getDietaryTag() const
{
    return dietaryTag;
}

std::string AllergenAlert::getType() const
{
    return "Allergen Alert";
}

void AllergenAlert::affect(EventComponent* component)
{
    if (component != nullptr)
    {
        component->onAllergenAlert(dietaryTag);
    }
}