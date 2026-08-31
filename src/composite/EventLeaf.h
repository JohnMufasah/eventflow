#ifndef EVENTLEAF_H
#define EVENTLEAF_H

#include "EventComponent.h"

/**
 * @file EventLeaf.h
 * @brief Defines the Leaf role in the EventFlow Composite pattern.
 */

/**
 * @class EventLeaf
 * @brief Base class representing a Leaf in the Composite pattern.
 *
 * EventLeaf objects represent components that cannot contain child
 * EventComponents. Concrete event objects such as StudentGuide,
 * FoodVendor and InformationDesk derive from this class.
 */
class EventLeaf : public EventComponent
{
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~EventLeaf() {}
};

#endif