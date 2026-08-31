/**
 * @file EventNotice.cpp
 * @brief Implements the base EventNotice class.
 */

#include "EventNotice.h"

EventNotice::EventNotice(
    const std::string& message,
    const std::string& location)
    : message(message),
      location(location)
{
}

std::string EventNotice::getMessage() const
{
    return message;
}

std::string EventNotice::getLocation() const
{
    return location;
}