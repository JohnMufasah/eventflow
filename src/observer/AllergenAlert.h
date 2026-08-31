#ifndef ALLERGENALERT_H
#define ALLERGENALERT_H

#include "EventNotice.h"

/**
 * @brief Notice concerning a dietary or allergen requirement.
 */
class AllergenAlert : public EventNotice
{
private:
    std::string dietaryTag;

public:
    /**
     * @brief Creates an allergen alert.
     *
     * @param message Description of the alert.
     * @param location Location where the alert applies.
     * @param dietaryTag Dietary or allergen tag involved.
     */
    AllergenAlert(
        const std::string& message,
        const std::string& location,
        const std::string& dietaryTag);

    /**
     * @brief Returns the dietary tag associated with the alert.
     */
    std::string getDietaryTag() const;

    /**
     * @brief Returns the notice type.
     */
    std::string getType() const override;

    /**
     * @brief Applies the allergen response to a component.
     *
     * @param component Component receiving the alert.
     */
    void affect(EventComponent* component) override;
};

#endif