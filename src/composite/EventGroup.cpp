/**
 * @file EventGroup.cpp
 * @brief Implements the EventFlow Composite hierarchy.
 */

#include "EventGroup.h"
#include "Leaves.h"

#include "../observer/EventNotice.h"
#include "../observer/CapacityAlert.h"
#include "../observer/EventNotificationHandler.h"

#include <algorithm>
#include <iostream>

EventGroup::EventGroup(const std::string& n)
    : name(n)
{
}

EventGroup::~EventGroup()
{
    children.clear();
}

std::string EventGroup::getTypeLabel() const
{
    return "Event Group";
}

void EventGroup::add(EventComponent* child)
{
    if (child != nullptr)
    {
        if (std::find(
                children.begin(),
                children.end(),
                child) == children.end())
        {
            children.push_back(child);
        }
    }
}

void EventGroup::remove(EventComponent* child)
{
    auto it = std::find(
        children.begin(),
        children.end(),
        child);

    if (it != children.end())
    {
        children.erase(it);
    }
}

void EventGroup::open()
{
    for (EventComponent* child : children)
    {
        if (child != nullptr)
        {
            child->open();
        }
    }
}

void EventGroup::close()
{
    for (EventComponent* child : children)
    {
        if (child != nullptr)
        {
            child->close();
        }
    }
}

void EventGroup::reportStatus() const
{
    std::cout << "["
              << getTypeLabel()
              << "] "
              << name
              << " ("
              << children.size()
              << " children)\n";

    for (const EventComponent* child : children)
    {
        if (child != nullptr)
        {
            child->reportStatus();
        }
    }
}

int EventGroup::getCapacity() const
{
    int total = 0;

    for (const EventComponent* child : children)
    {
        if (child != nullptr)
        {
            total += child->getCapacity();
        }
    }

    return total;
}

void EventGroup::handleNotice(EventNotice* notice)
{
    if (notice == nullptr)
    {
        return;
    }

    notice->affect(this);

    for (EventComponent* child : children)
    {
        if (child != nullptr)
        {
            child->handleNotice(notice);
        }
    }
}

const std::vector<EventComponent*>&
EventGroup::getChildren() const
{
    return children;
}

OpenDay::OpenDay(const std::string& n)
    : EventGroup(n)
{
}

std::string OpenDay::getTypeLabel() const
{
    return "Open Day";
}

Faculty::Faculty(const std::string& n)
    : EventGroup(n)
{
}

std::string Faculty::getTypeLabel() const
{
    return "Faculty";
}

EventZone::EventZone(
    const std::string& n,
    int capacity,
    bool laboratory)
    : EventGroup(n),
      visitorCount(0),
      capacityLimit(capacity),
      laboratoryZone(laboratory)
{
}

bool EventZone::admitVisitor(const Visitor& visitor)
{
    if (visitorCount >= capacityLimit)
    {
        std::cout
            << "Capacity reached at "
            << name
            << ". Visitor "
            << visitor.getName()
            << " cannot be admitted.\n";

        CapacityAlert alert(
            "Event zone has reached capacity.",
            name,
            laboratoryZone);

        notify(&alert);

        return false;
    }

    ++visitorCount;

    std::cout
        << visitor.getName()
        << " admitted to "
        << name
        << " ("
        << visitorCount
        << "/"
        << capacityLimit
        << ").\n";

    return true;
}

int EventZone::getVisitorCount() const
{
    return visitorCount;
}

int EventZone::getCapacityLimit() const
{
    return capacityLimit;
}

bool EventZone::isLaboratoryZone() const
{
    return laboratoryZone;
}

int EventZone::getCapacity() const
{
    return capacityLimit;
}

void EventZone::onCapacityAlert()
{
    if (!laboratoryZone)
    {
        return;
    }

    for (EventComponent* child : children)
    {
        SafetyBriefing* briefing =
            dynamic_cast<SafetyBriefing*>(child);

        if (briefing != nullptr)
        {
            briefing->onSafetyBriefingReminder();
        }
    }
}

void EventZone::attach(Observer* observer)
{
    if (observer == nullptr)
    {
        return;
    }

    if (std::find(
            observers.begin(),
            observers.end(),
            observer) == observers.end())
    {
        observers.push_back(observer);
    }
}

void EventZone::detach(Observer* observer)
{
    auto it = std::find(
        observers.begin(),
        observers.end(),
        observer);

    if (it != observers.end())
    {
        observers.erase(it);
    }
}

void EventZone::notify(EventNotice* notice)
{
    if (notice == nullptr)
    {
        return;
    }

    for (Observer* observer : observers)
    {
        if (observer != nullptr)
        {
            observer->update(notice);
        }
    }

    notice->affect(this);
}

std::string EventZone::getTypeLabel() const
{
    return "Event Zone";
}

ExhibitionZone::ExhibitionZone(
    const std::string& n,
    int capacity)
    : EventZone(n, capacity, false)
{
}

bool ExhibitionZone::isCongested() const
{
    if (capacityLimit <= 0)
    {
        return false;
    }

    return visitorCount >=
           static_cast<int>(capacityLimit * 0.9);
}

bool ExhibitionZone::moveGuide(
    StudentGuide* guide,
    ExhibitionZone* newZone,
    EventNotificationHandler* handler)
{
    if (guide == nullptr ||
        newZone == nullptr ||
        handler == nullptr)
    {
        return false;
    }

    remove(guide);
    detach(handler);

    handler->setTarget(guide);

    newZone->add(guide);
    newZone->attach(handler);

    std::cout
        << "StudentGuide moved from "
        << name
        << " to the new ExhibitionZone.\n";

    return true;
}

std::string ExhibitionZone::getTypeLabel() const
{
    return "Exhibition Zone";
}

CampusServices::CampusServices(const std::string& n)
    : EventGroup(n)
{
}

std::string CampusServices::getTypeLabel() const
{
    return "Campus Services";
}