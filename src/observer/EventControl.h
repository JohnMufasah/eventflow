#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include <vector>

#include "Subject.h"

class EventControl : public Subject
{
private:
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) override;
    void detach(Observer* observer) override;
    void notify(EventNotice* notice) override;
};

#endif