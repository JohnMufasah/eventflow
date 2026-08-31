#ifndef EVENTLEAF_H
#define EVENTLEAF_H

#include "EventComponent.h"

/**
 * @brief Marker abstraction for the Leaf role - a leaf has no children
 * and cannot contain other EventComponents. Deliberately adds no new
 * members of its own; concrete leaves implement everything through the
 * EventComponent interface directly. Exists mainly so the Composite vs
 * Leaf distinction is explicit in the class hierarchy, matching the
 * team's class diagram.
 */
class EventLeaf : public EventComponent {
};

#endif
