#ifndef DEPARTMENTMISMATCH_H
#define DEPARTMENTMISMATCH_H

#include "EventNotice.h"

/**
 * @brief Notice indicating that a visitor is in the wrong faculty.
 */
class DepartmentMismatch : public EventNotice
{
private:
    std::string correctFaculty;

public:
    /**
     * @brief Creates a department mismatch notice.
     *
     * @param message Description of the mismatch.
     * @param location Location associated with the notice.
     * @param correctFaculty Faculty the visitor should be directed to.
     */
    DepartmentMismatch(
        const std::string& message,
        const std::string& location,
        const std::string& correctFaculty);

    /**
     * @brief Returns the correct faculty.
     */
    std::string getCorrectFaculty() const;

    /**
     * @brief Returns the notice type.
     */
    std::string getType() const override;

    /**
     * @brief Applies the department mismatch response.
     *
     * @param component Component receiving the notice.
     */
    void affect(EventComponent* component) override;
};

#endif