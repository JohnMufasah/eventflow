/**
 * @file Visitor.cpp
 * @brief Implements the Visitor class.
 */

#include "Visitor.h"

Visitor::Visitor(
    const std::string& name,
    const std::string& faculty)
    : name(name),
      faculty(faculty)
{
}

std::string Visitor::getName() const
{
    return name;
}

std::string Visitor::getFaculty() const
{
    return faculty;
}