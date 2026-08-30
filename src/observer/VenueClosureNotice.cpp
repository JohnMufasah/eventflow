#include "VenueClosureNotice.h"

VenueClosureNotice::VenueClosureNotice(const std::string& message,
                                       const std::string& location,
                                       const std::string& venue)
    : EventNotice(message, location),
      venue(venue)
{
}

std::string VenueClosureNotice::getVenue() const
{
    return venue;
}