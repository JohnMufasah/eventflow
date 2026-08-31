/**
 * @file AllergenAlert.h
 * @brief Defines allergen alert notifications for the EventFlow system.
 */

#ifndef ALLERGENALERT_H
#define ALLERGENALERT_H

#include "EventNotice.h"

/**
 * @class AllergenAlert
 * @brief Represents a notification concerning an undeclared allergen.
 *
 * The alert contains the dietary/allergen tag associated with the
 * notification. FoodVendor components can use this information to
 * determine whether they need to react.
 */
class AllergenAlert : public EventNotice
{
private:

    /// Dietary or allergen tag associated with the alert.
    std::string dietaryTag;

public:

    /**
     * @brief Constructs an allergen alert.
     *
     * @param message Description of the allergen issue.
     * @param location Location associated with the alert.
     * @param dietaryTag Dietary or allergen tag associated with the alert.
     */
    AllergenAlert(const std::string& message,
                  const std::string& location,
                  const std::string& dietaryTag);

    /**
     * @brief Gets the dietary/allergen tag.
     *
     * @return The dietary/allergen tag associated with the alert.
     */
    std::string getDietaryTag() const;

    /**
     * @brief Returns the notification type.
     *
     * @return "Allergen Alert".
     */
    std::string getType() const override;

    /**
     * @brief Applies the allergen alert to an EventComponent.
     *
     * @param component Component receiving the alert.
     */
    void affect(EventComponent* component) override;
};

#endif