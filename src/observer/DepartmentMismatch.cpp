#include "DepartmentMismatch.h"
#include "../composite/EventComponent.h"

DepartmentMismatch::DepartmentMismatch(
    const std::string& message,
    const std::string& location,
    const std::string& correctFaculty)
    : EventNotice(message, location),
      correctFaculty(correctFaculty)
{
}

std::string DepartmentMismatch::getCorrectFaculty() const
{
    return correctFaculty;
}

std::string DepartmentMismatch::getType() const
{
    return "Department Mismatch";
}

void DepartmentMismatch::affect(EventComponent* component)
{
    if (component != nullptr)
    {
        component->onDepartmentMismatch(correctFaculty);
    }
}