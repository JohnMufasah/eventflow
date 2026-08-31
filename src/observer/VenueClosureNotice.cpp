/**
 * @file VenueClosureNotice.cpp
 * @brief Implements venue closure notifications.
 */

#include "VenueClosureNotice.h"
#include "../composite/EventComponent.h"

/**
 * @brief Constructs a VenueClosureNotice.
 *
 * @param message Description of the venue closure.
 * @param location Location associated with the closure.
 * @param venue Name of the venue that has been closed.
 */
VenueClosureNotice::VenueClosureNotice(const std::string& message,
                                       const std::string& location,
                                       const std::string& venue)
    : EventNotice(message, location),
      venue(venue)
{
}

/**
 * @brief Gets the affected venue.
 *
 * @return Name of the closed venue.
 */
std::string VenueClosureNotice::getVenue() const
{
    return venue;
}

/**
 * @brief Returns the notification type.
 *
 * @return "Venue Closure".
 */
std::string VenueClosureNotice::getType() const
{
    return "Venue Closure";
}

/**
 * @brief Applies the venue closure notification.
 *
 * Delegates the response to the receiving component's
 * onVenueClosure() handler.
 *
 * @param component Component receiving the notification.
 */
void VenueClosureNotice::affect(EventComponent* component)
{
    if (component != nullptr)
    {
        component->onVenueClosure();
    }
}