#include "EventGroup.h"
#include "EventNotice.h"
#include <algorithm>
#include <iostream>

EventGroup::EventGroup(const std::string& n) : name(n) {}

EventGroup::~EventGroup() {
    for (EventComponent* child : children) {
        delete child;
    }

    children.clear();
}

std::string EventGroup::getTypeLabel() const { return "Event Group"; }

void EventGroup::add(EventComponent* child) {
    children.push_back(child);
}

void EventGroup::remove(EventComponent* child) {
    auto it = std::find(children.begin(), children.end(), child);

    if (it != children.end()) {
        children.erase(it); 
    }
}

void EventGroup::open() {
    for (EventComponent* child : children) child->open();
}

void EventGroup::close() {
    for (EventComponent* child : children) child->close();
}

void EventGroup::reportStatus() const {
    std::cout << "[" << getTypeLabel() << "] " << name << " (" << children.size() << " children)\n";
    for (const EventComponent* child : children) {
        child->reportStatus();
    }
}

int EventGroup::getCapacity() const {
    int total = 0;
    for (const EventComponent* child : children) {
        total += child->getCapacity();
    }
    return total;
}

void EventGroup::handleNotice(EventNotice* notice) {
    notice->affect(this);
    for (EventComponent* child : children) {
        child->handleNotice(notice);
    }
}

OpenDay::OpenDay(const std::string& n) : EventGroup(n) {}

std::string OpenDay::getTypeLabel() const { 
    return "Open Day"; 
}

Faculty::Faculty(const std::string& n) : EventGroup(n) {}

std::string Faculty::getTypeLabel() const { 
    return "Faculty"; 
}

EventZone::EventZone(const std::string& n) : EventGroup(n) {}

std::string EventZone::getTypeLabel() const { 
    return "Event Zone"; 
}

CampusServices::CampusServices(const std::string& n) : EventGroup(n) {}

std::string CampusServices::getTypeLabel() const { 
    return "Campus Services"; 
}
