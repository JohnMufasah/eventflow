#ifndef VISITOR_H
#define VISITOR_H

#include <string>

/**
 * @file Visitor.h
 * @brief Defines the Visitor class used by EventFlow.
 */

/**
 * @class Visitor
 * @brief Represents a visitor attending the University Open Day.
 *
 * A Visitor has an identity and a faculty or department that can be
 * used to determine whether the visitor is in the correct faculty.
 */
class Visitor
{
private:
    /** @brief Visitor's name. */
    std::string name;

    /** @brief Faculty associated with the visitor. */
    std::string faculty;

public:
    /**
     * @brief Constructs a Visitor.
     *
     * @param name Visitor's name.
     * @param faculty Faculty the visitor is interested in.
     */
    Visitor(
        const std::string& name,
        const std::string& faculty);

    /**
     * @brief Gets the visitor's name.
     *
     * @return Visitor's name.
     */
    std::string getName() const;

    /**
     * @brief Gets the visitor's faculty.
     *
     * @return Faculty associated with the visitor.
     */
    std::string getFaculty() const;
};

#endif