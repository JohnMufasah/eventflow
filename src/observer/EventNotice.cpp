/**
 * @file EventNotice.cpp
 * @brief Implements the base EventNotice functionality.
 */

#include "EventNotice.h"

/**
 * @brief Constructs an EventNotice.
 *
 * Initializes the message and location associated with the notification.
 *
 * @param message Description of the event notification.
 * @param location Location associated with the notification.
 */
EventNotice::EventNotice(const std::string& message,
                         const std::string& location)
    : message(message),
      location(location)
{
}

/**
 * @brief Gets the notification message.
 *
 * @return The message describing the event change.
 */
std::string EventNotice::getMessage() const
{
    return message;
}

/**
 * @brief Gets the location associated with the notification.
 *
 * @return The location associated with the event change.
 */
std::string EventNotice::getLocation() const
{
    return location;
}