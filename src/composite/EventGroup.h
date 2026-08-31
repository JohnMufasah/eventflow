#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
#include <string>
#include <vector>

/**
 * @brief Composite role - owns its children and recursively implements
 * the common operations. OpenDay, Faculty, EventZone, and CampusServices
 * are thin concrete subclasses of this, so a Faculty can contain
 * EventZones and an EventZone can contain Leaves, all through the same
 * vector<EventComponent*> mechanism.
 */
class EventGroup : public EventComponent {
protected:
    std::string name;
    std::vector<EventComponent*> children;
    virtual std::string getTypeLabel() const;

public:
    explicit EventGroup(const std::string& name);
    ~EventGroup() override; // deletes every remaining owned child

    EventGroup(const EventGroup&) = delete;
    EventGroup& operator=(const EventGroup&) = delete;

    /// Ownership transfers to this EventGroup.
    void add(EventComponent* child);
    void remove(EventComponent* child);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;
};

class OpenDay : public EventGroup {
public:
    explicit OpenDay(const std::string& name);
protected:
    std::string getTypeLabel() const override;
};

class Faculty : public EventGroup {
public:
    explicit Faculty(const std::string& name);
protected:
    std::string getTypeLabel() const override;
};

class EventZone : public EventGroup {
public:
    explicit EventZone(const std::string& name);
protected:
    std::string getTypeLabel() const override;
};

class CampusServices : public EventGroup {
public:
    explicit CampusServices(const std::string& name);
protected:
    std::string getTypeLabel() const override;
};

#endif
