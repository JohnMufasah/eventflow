/**
 * @file EventNotice.h
 * @brief Defines the base class for EventFlow notifications.
 */

#ifndef EVENTNOTICE_H
#define EVENTNOTICE_H

#include <string>

/**
 * @class EventNotice
 * @brief Abstract base class representing an event notification.
 *
 * EventNotice provides common information shared by different
 * notification types in the EventFlow system.
 *
 * Concrete notice classes extend this class to provide information
 * specific to a particular type of event change.
 */
class EventNotice
{
protected:

    /// Human-readable description of the event change.
    std::string message;

    /// Location associated with the event change.
    std::string location;

public:

    /**
     * @brief Constructs an EventNotice.
     *
     * @param message Description of the event change.
     * @param location Location associated with the change.
     */
    EventNotice(const std::string& message,
                const std::string& location);

    /**
     * @brief Virtual destructor for the EventNotice hierarchy.
     */
    virtual ~EventNotice() = default;

    /**
     * @brief Gets the notification message.
     *
     * @return The message describing the event change.
     */
    std::string getMessage() const;

    /**
     * @brief Gets the location associated with the notification.
     *
     * @return The location associated with the event change.
     */
    std::string getLocation() const;

    /**
     * @brief Gets the type of notification.
     *
     * @return A string identifying the concrete notification type.
     */
    virtual std::string getType() const = 0;
};

#endif