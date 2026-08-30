#ifndef VENUECLOSURENOTICE_H
#define VENUECLOSURENOTICE_H

#include "EventNotice.h"

class VenueClosureNotice : public EventNotice
{
private:
    std::string venue;

public:
    VenueClosureNotice(const std::string& message,
                       const std::string& location,
                       const std::string& venue);

    std::string getVenue() const;
};

#endif