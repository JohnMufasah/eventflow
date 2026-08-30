#include "RoomChangeNotice.h"

RoomChangeNotice::RoomChangeNotice(const std::string& message,
                                   const std::string& location,
                                   const std::string& oldRoom,
                                   const std::string& newRoom)
    : EventNotice(message, location),
      oldRoom(oldRoom),
      newRoom(newRoom)
{
}

std::string RoomChangeNotice::getOldRoom() const
{
    return oldRoom;
}

std::string RoomChangeNotice::getNewRoom() const
{
    return newRoom;
}