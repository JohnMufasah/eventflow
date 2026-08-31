/**
 * @file RoomChangeNotice.h
 * @brief Defines notifications for room changes.
 */

#ifndef ROOMCHANGENOTICE_H
#define ROOMCHANGENOTICE_H

#include "EventNotice.h"

/**
 * @class RoomChangeNotice
 * @brief Represents a notification that an event has moved rooms.
 */
class RoomChangeNotice : public EventNotice
{
private:

    /// Room from which the event was moved.
    std::string oldRoom;

    /// New room assigned to the event.
    std::string newRoom;

public:

    /**
     * @brief Constructs a room change notification.
     *
     * @param message Description of the room change.
     * @param location Location associated with the change.
     * @param oldRoom Previous room.
     * @param newRoom New room.
     */
    RoomChangeNotice(const std::string& message,
                     const std::string& location,
                     const std::string& oldRoom,
                     const std::string& newRoom);

    /**
     * @brief Gets the previous room.
     *
     * @return Name of the previous room.
     */
    std::string getOldRoom() const;

    /**
     * @brief Gets the new room.
     *
     * @return Name of the new room.
     */
    std::string getNewRoom() const;

    /**
     * @brief Returns the notification type.
     *
     * @return "Room Change".
     */
    std::string getType() const override;
};

#endif