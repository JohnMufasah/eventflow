#include "EventControl.h"
#include "Observer.h"
#include "EventNotice.h"

#include <algorithm>

void EventControl::attach(Observer* observer)
{
    observers.push_back(observer);
}

void EventControl::detach(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);

    if(it != observers.end()){
        observers.erase(it);
    }
}

void EventControl::notify(EventNotice* notice) {
    for (Observer* observer : observers) {
        observer->update(notice);
    }
}