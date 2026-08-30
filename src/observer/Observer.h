#ifndef OBSERVER_H
#define OBSERVER_H

class EventNotice;

class Observer
{
public:
    virtual void update(EventNotice* notice) = 0;

    virtual ~Observer() = default;
};

#endif