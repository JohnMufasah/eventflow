#ifndef VENUECLOSURENOTICE_H
#define VENUECLOSURENOTICE_H

#include "EventNotice.h"

/**
 * @brief Notice indicating that a venue has been closed.
 */
class VenueClosureNotice : public EventNotice
{
private:
    std::string venue;

public:
    /**
     * @brief Creates a venue closure notice.
     *
     * @param message Description of the closure.
     * @param location Location associated with the closure.
     * @param venue Name of the closed venue.
     */
    VenueClosureNotice(
        const std::string& message,
        const std::string& location,
        const std::string& venue);

    /**
     * @brief Returns the closed venue.
     */
    std::string getVenue() const;

    /**
     * @brief Returns the notice type.
     */
    std::string getType() const override;

    /**
     * @brief Applies the venue closure.
     *
     * @param component Component receiving the notice.
     */
    void affect(EventComponent* component) override;
};

#endif