#ifndef CAPACITYUPDATENOTICE_H
#define CAPACITYUPDATENOTICE_H

#include "EventNotice.h"

/**
 * @brief Notice indicating that an event capacity has changed.
 */
class CapacityUpdateNotice : public EventNotice
{
private:
    int oldCapacity;
    int newCapacity;

public:
    /**
     * @brief Creates a capacity update notice.
     *
     * @param message Description of the capacity change.
     * @param location Location associated with the change.
     * @param oldCapacity Previous capacity.
     * @param newCapacity New capacity.
     */
    CapacityUpdateNotice(
        const std::string& message,
        const std::string& location,
        int oldCapacity,
        int newCapacity);

    /**
     * @brief Returns the previous capacity.
     */
    int getOldCapacity() const;

    /**
     * @brief Returns the new capacity.
     */
    int getNewCapacity() const;

    /**
     * @brief Returns the notice type.
     */
    std::string getType() const override;

    /**
     * @brief Applies the capacity update.
     *
     * @param component Component receiving the notice.
     */
    void affect(EventComponent* component) override;
};

#endif