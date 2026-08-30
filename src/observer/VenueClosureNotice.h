/**
 * @file VenueClosureNotice.h
 * @brief Defines notifications for venue closures.
 */

#ifndef VENUECLOSURENOTICE_H
#define VENUECLOSURENOTICE_H

#include "EventNotice.h"

/**
 * @class VenueClosureNotice
 * @brief Represents a notification that a venue has been closed.
 *
 * VenueClosureNotice extends EventNotice with the specific venue
 * affected by the closure.
 */
class VenueClosureNotice : public EventNotice
{
private:

    /// Name of the venue that has been closed.
    std::string venue;

public:

    /**
     * @brief Constructs a venue closure notification.
     *
     * @param message Description of the closure.
     * @param location Location associated with the closure.
     * @param venue Name of the venue that has been closed.
     */
    VenueClosureNotice(const std::string& message,
                       const std::string& location,
                       const std::string& venue);

    /**
     * @brief Gets the closed venue.
     *
     * @return Name of the venue affected by the closure.
     */
    std::string getVenue() const;

    /**
     * @brief Returns the notification type.
     *
     * @return "Venue Closure".
     */
    std::string getType() const override;
};

#endif