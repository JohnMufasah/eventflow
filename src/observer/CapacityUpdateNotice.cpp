/**
 * @file CapacityUpdateNotice.cpp
 * @brief Implements capacity update notifications.
 */

#include "CapacityUpdateNotice.h"
#include "../composite/EventComponent.h"

/**
 * @brief Constructs a CapacityUpdateNotice.
 *
 * @param message Description of the capacity change.
 * @param location Location associated with the change.
 * @param oldCapacity Previous capacity.
 * @param newCapacity Updated capacity.
 */
CapacityUpdateNotice::CapacityUpdateNotice(const std::string& message,
                                           const std::string& location,
                                           int oldCapacity,
                                           int newCapacity)
    : EventNotice(message, location),
      oldCapacity(oldCapacity),
      newCapacity(newCapacity)
{
}

/**
 * @brief Gets the previous capacity.
 *
 * @return Previous capacity value.
 */
int CapacityUpdateNotice::getOldCapacity() const
{
    return oldCapacity;
}

/**
 * @brief Gets the updated capacity.
 *
 * @return New capacity value.
 */
int CapacityUpdateNotice::getNewCapacity() const
{
    return newCapacity;
}

/**
 * @brief Returns the notification type.
 *
 * @return "Capacity Update".
 */
std::string CapacityUpdateNotice::getType() const
{
    return "Capacity Update";
}

/**
 * @brief Applies the capacity update notification.
 *
 * Delegates the response to the receiving component's
 * onCapacityUpdate() handler.
 *
 * @param component Component receiving the notification.
 */
void CapacityUpdateNotice::affect(EventComponent* component)
{
    if (component != nullptr)
    {
        component->onCapacityUpdate(newCapacity);
    }
}