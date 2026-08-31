#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
#include "../event/Visitor.h"
#include "../observer/Subject.h"

#include <string>
#include <vector>

class Observer;
class StudentGuide;
class SafetyBriefing;
class EventNotificationHandler;

/**
 * @brief Composite component that can contain other EventComponents.
 *
 * EventGroup implements the Composite pattern used to build the
 * EventFlow hierarchy.
 */
class EventGroup : public EventComponent
{
protected:
    std::string name;
    std::vector<EventComponent*> children;

    virtual std::string getTypeLabel() const;

public:
    /**
     * @brief Constructs an event group.
     *
     * @param name Name of the group.
     */
    explicit EventGroup(const std::string& name);

    /**
     * @brief Destroys the event group.
     *
     * EventGroup does not own its child components.
     */
    ~EventGroup() override;

    EventGroup(const EventGroup&) = delete;
    EventGroup& operator=(const EventGroup&) = delete;

    /**
     * @brief Adds a child component to the group.
     *
     * @param child Component to add.
     */
    void add(EventComponent* child);

    /**
     * @brief Removes a child component from the group.
     *
     * @param child Component to remove.
     */
    void remove(EventComponent* child);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    /**
     * @brief Returns the components contained in the group.
     *
     * @return Reference to the list of child components.
     */
    const std::vector<EventComponent*>& getChildren() const;
};


/**
 * @brief Represents the University Open Day.
 */
class OpenDay : public EventGroup
{
public:
    /**
     * @brief Constructs an OpenDay.
     *
     * @param name Name of the open day.
     */
    explicit OpenDay(const std::string& name);

protected:
    std::string getTypeLabel() const override;
};


/**
 * @brief Represents a faculty within the event hierarchy.
 */
class Faculty : public EventGroup
{
public:
    /**
     * @brief Constructs a Faculty.
     *
     * @param name Name of the faculty.
     */
    explicit Faculty(const std::string& name);

protected:
    std::string getTypeLabel() const override;
};


/**
 * @brief Represents a zone within the event.
 *
 * EventZone acts as a Subject in the Observer pattern, allowing
 * observers such as StudentGuide to be attached and moved between
 * zones at runtime.
 */
class EventZone : public EventGroup,
                  public Subject
{
protected:
    int visitorCount;
    int capacityLimit;
    bool laboratoryZone;

    std::vector<Observer*> observers;

public:
    /**
     * @brief Constructs an event zone.
     *
     * @param name Name of the zone.
     * @param capacityLimit Maximum number of visitors.
     * @param laboratoryZone Whether the zone is a laboratory.
     */
    EventZone(
        const std::string& name,
        int capacityLimit,
        bool laboratoryZone = false);

    /**
     * @brief Attempts to admit a visitor into the zone.
     *
     * @param visitor Visitor attempting to enter.
     * @return true if the visitor was admitted, otherwise false.
     */
    bool admitVisitor(const Visitor& visitor);

    /**
     * @brief Returns the current number of visitors.
     *
     * @return Current visitor count.
     */
    int getVisitorCount() const;

    /**
     * @brief Returns the maximum visitor capacity.
     *
     * @return Maximum capacity.
     */
    int getCapacityLimit() const;

    /**
     * @brief Checks whether this is a laboratory zone.
     *
     * @return true if the zone is a laboratory, otherwise false.
     */
    bool isLaboratoryZone() const;

    int getCapacity() const override;

    /**
     * @brief Handles a capacity alert.
     */
    void onCapacityAlert() override;

    void attach(Observer* observer) override;
    void detach(Observer* observer) override;
    void notify(EventNotice* notice) override;

protected:
    std::string getTypeLabel() const override;
};


/**
 * @brief Represents an exhibition area.
 *
 * An exhibition is considered congested when it reaches at least
 * 90 percent of its capacity.
 */
class ExhibitionZone : public EventZone
{
public:
    /**
     * @brief Constructs an exhibition zone.
     *
     * @param name Name of the exhibition.
     * @param capacityLimit Maximum visitor capacity.
     */
    ExhibitionZone(
        const std::string& name,
        int capacityLimit);

    /**
     * @brief Checks whether the exhibition is congested.
     *
     * @return true when occupancy is at least 90 percent.
     */
    bool isCongested() const;

    /**
     * @brief Moves a StudentGuide to another exhibition zone.
     *
     * The method updates both the Composite hierarchy and the
     * Observer relationship.
     *
     * @param guide StudentGuide being moved.
     * @param destination Exhibition zone receiving the guide.
     * @param handler Observer handler associated with the guide.
     * @return true if the guide was moved successfully.
     */
    bool moveGuide(
        StudentGuide* guide,
        ExhibitionZone* destination,
        EventNotificationHandler* handler);

protected:
    std::string getTypeLabel() const override;
};


/**
 * @brief Represents services provided across the campus.
 */
class CampusServices : public EventGroup
{
public:
    /**
     * @brief Constructs a CampusServices group.
     *
     * @param name Name of the services group.
     */
    explicit CampusServices(const std::string& name);

protected:
    std::string getTypeLabel() const override;
};

#endif