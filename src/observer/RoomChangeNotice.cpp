#include "RoomChangeNotice.h"
#include "../composite/EventComponent.h"

RoomChangeNotice::RoomChangeNotice(
    const std::string& message,
    const std::string& location,
    const std::string& newRoom)
    : EventNotice(message, location),
      newRoom(newRoom)
{
}

std::string RoomChangeNotice::getNewRoom() const
{
    return newRoom;
}

std::string RoomChangeNotice::getType() const
{
    return "Room Change";
}

void RoomChangeNotice::affect(EventComponent* component)
{
    if (component != nullptr)
    {
        component->onRoomChange(newRoom);
    }
}