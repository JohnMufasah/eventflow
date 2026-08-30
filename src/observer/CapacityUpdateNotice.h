#ifndef CAPACITYUPDATENOTICE_H
#define CAPACITYUPDATENOTICE_H

#include "EventNotice.h"

class CapacityUpdateNotice : public EventNotice
{
private:
    int oldCapacity;
    int newCapacity;

public:
    CapacityUpdateNotice(const std::string& message,
                          const std::string& location,
                          int oldCapacity,
                          int newCapacity);

    int getOldCapacity() const;
    int getNewCapacity() const;
};

#endif