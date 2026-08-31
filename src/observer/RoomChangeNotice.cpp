/**
 * @file RoomChangeNotice.cpp
 * @brief Implements room change notifications.
 */

#include "RoomChangeNotice.h"
#include "../composite/EventComponent.h"

/**
 * @brief Constructs a RoomChangeNotice.
 *
 * @param message Description of the room change.
 * @param location Location associated with the change.
 * @param oldRoom Previous room assigned to the event.
 * @param newRoom New room assigned to the event.
 */
RoomChangeNotice::RoomChangeNotice(const std::string& message,
                                   const std::string& location,
                                   const std::string& oldRoom,
                                   const std::string& newRoom)
    : EventNotice(message, location),
      oldRoom(oldRoom),
      newRoom(newRoom)
{
}

/**
 * @brief Gets the previous room.
 *
 * @return Name of the previous room.
 */
std::string RoomChangeNotice::getOldRoom() const
{
    return oldRoom;
}

/**
 * @brief Gets the new room.
 *
 * @return Name of the new room.
 */
std::string RoomChangeNotice::getNewRoom() const
{
    return newRoom;
}

/**
 * @brief Returns the notification type.
 *
 * @return "Room Change".
 */
std::string RoomChangeNotice::getType() const
{
    return "Room Change";
}

/**
 * @brief Applies the room change notification.
 *
 * Delegates the response to the receiving component's
 * onRoomChange() handler.
 *
 * @param component Component receiving the notification.
 */
void RoomChangeNotice::affect(EventComponent* component)
{
    if (component != nullptr)
    {
        component->onRoomChange(newRoom);
    }
}