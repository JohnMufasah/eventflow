#ifndef SUBJECT_H
#define SUBJECT_H

class Observer;
class EventNotice;

class Subject
{
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify(EventNotice* notice) = 0;

    virtual ~Subject() = default;
};

#endif