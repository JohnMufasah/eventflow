/**
 * @file CapacityUpdateNotice.h
 * @brief Defines notifications for capacity changes.
 */

#ifndef CAPACITYUPDATENOTICE_H
#define CAPACITYUPDATENOTICE_H

#include "EventNotice.h"

/**
 * @class CapacityUpdateNotice
 * @brief Represents a notification that an event capacity has changed.
 */
class CapacityUpdateNotice : public EventNotice
{
private:

    /// Previous capacity of the affected component.
    int oldCapacity;

    /// New capacity of the affected component.
    int newCapacity;

public:

    /**
     * @brief Constructs a capacity update notification.
     *
     * @param message Description of the capacity change.
     * @param location Location associated with the change.
     * @param oldCapacity Previous capacity.
     * @param newCapacity New capacity.
     */
    CapacityUpdateNotice(const std::string& message,
                          const std::string& location,
                          int oldCapacity,
                          int newCapacity);

    /**
     * @brief Gets the previous capacity.
     *
     * @return Previous capacity.
     */
    int getOldCapacity() const;

    /**
     * @brief Gets the new capacity.
     *
     * @return New capacity.
     */
    int getNewCapacity() const;

    /**
     * @brief Returns the notification type.
     *
     * @return "Capacity Update".
     */
    std::string getType() const override;

    /**
 * @brief Applies the capacity update notification to an EventComponent.
 *
 * @param component Component receiving the notification.
 */
void affect(EventComponent* component) override;
};

#endif