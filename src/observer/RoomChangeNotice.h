#ifndef ROOMCHANGENOTICE_H
#define ROOMCHANGENOTICE_H

#include "EventNotice.h"

/**
 * @brief Notice indicating that an event has moved to another room.
 */
class RoomChangeNotice : public EventNotice
{
private:
    std::string newRoom;

public:
    /**
     * @brief Creates a room change notice.
     *
     * @param message Description of the room change.
     * @param location Current location of the event.
     * @param newRoom New room for the event.
     */
    RoomChangeNotice(
        const std::string& message,
        const std::string& location,
        const std::string& newRoom);

    /**
     * @brief Returns the new room.
     */
    std::string getNewRoom() const;

    /**
     * @brief Returns the notice type.
     */
    std::string getType() const override;

    /**
     * @brief Applies the room change to a component.
     *
     * @param component Component receiving the notice.
     */
    void affect(EventComponent* component) override;
};

#endif