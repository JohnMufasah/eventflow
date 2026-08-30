#include "CapacityUpdateNotice.h"

CapacityUpdateNotice::CapacityUpdateNotice(const std::string& message,
                                           const std::string& location,
                                           int oldCapacity,
                                           int newCapacity)
    : EventNotice(message, location),
      oldCapacity(oldCapacity),
      newCapacity(newCapacity)
{
}

int CapacityUpdateNotice::getOldCapacity() const
{
    return oldCapacity;
}

int CapacityUpdateNotice::getNewCapacity() const
{
    return newCapacity;
}