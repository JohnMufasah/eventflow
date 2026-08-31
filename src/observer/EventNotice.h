#ifndef EVENTNOTICE_H
#define EVENTNOTICE_H

#include <string>

class EventComponent;

/**
 * @brief Base class for notifications used by EventFlow.
 */
class EventNotice
{
protected:
    std::string message;
    std::string location;

public:
    /**
     * @brief Creates an event notice.
     *
     * @param message Description of the notice.
     * @param location Location associated with the notice.
     */
    EventNotice(
        const std::string& message,
        const std::string& location);

    /**
     * @brief Virtual destructor.
     */
    virtual ~EventNotice() = default;

    /**
     * @brief Returns the notice message.
     */
    std::string getMessage() const;

    /**
     * @brief Returns the location associated with the notice.
     */
    std::string getLocation() const;

    /**
     * @brief Returns the type of notice.
     */
    virtual std::string getType() const = 0;

    /**
     * @brief Applies the notice to an event component.
     *
     * @param component Component receiving the notice.
     */
    virtual void affect(EventComponent* component) = 0;
};

#endif