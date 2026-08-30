#ifndef ROOMCHANGENOTICE_H
#define ROOMCHANGENOTICE_H

#include "EventNotice.h"

class RoomChangeNotice : public EventNotice
{
private:
    std::string oldRoom;
    std::string newRoom;

public:
    RoomChangeNotice(const std::string& message,
                     const std::string& location,
                     const std::string& oldRoom,
                     const std::string& newRoom);

    std::string getOldRoom() const;
    std::string getNewRoom() const;
};

#endif