/**
 * @file AllergenAlert.cpp
 * @brief Implements allergen alert notifications.
 */

#include "AllergenAlert.h"
#include "../composite/EventComponent.h"

/**
 * @brief Constructs an AllergenAlert.
 *
 * @param message Description of the allergen issue.
 * @param location Location associated with the alert.
 * @param dietaryTag Dietary or allergen tag associated with the alert.
 */
AllergenAlert::AllergenAlert(const std::string& message,
                             const std::string& location,
                             const std::string& dietaryTag)
    : EventNotice(message, location),
      dietaryTag(dietaryTag)
{
}

/**
 * @brief Gets the dietary or allergen tag.
 *
 * @return Dietary/allergen tag associated with the alert.
 */
std::string AllergenAlert::getDietaryTag() const
{
    return dietaryTag;
}

/**
 * @brief Returns the notification type.
 *
 * @return "Allergen Alert".
 */
std::string AllergenAlert::getType() const
{
    return "Allergen Alert";
}

/**
 * @brief Applies an allergen alert to an EventComponent.
 *
 * The dietary tag is passed to the receiving component so that
 * a FoodVendor can determine whether the alert applies to its
 * own dietary options.
 *
 * @param component Component receiving the alert.
 */
void AllergenAlert::affect(EventComponent* component)
{
    if (component != nullptr)
    {
        component->onAllergenAlert(dietaryTag);
    }
}