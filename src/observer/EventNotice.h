#ifndef EVENTNOTICE_H
#define EVENTNOTICE_H

#include <string>

class EventNotice
{
protected:
    std::string message;
    std::string location;

public:
    EventNotice(const std::string& message,
                const std::string& location);

    virtual ~EventNotice() = default;

    std::string getMessage() const;
    std::string getLocation() const;
};

#endif