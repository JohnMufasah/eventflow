#ifndef LEAVES_H
#define LEAVES_H

#include "EventLeaf.h"

#include <set>
#include <string>

/**
 * @brief Provides safety information to visitors.
 */
class SafetyBriefing : public EventLeaf
{
private:
    std::string name;
    int capacity;
    bool extended;

public:
    /**
     * @brief Constructs a safety briefing.
     *
     * @param name Name of the briefing.
     * @param capacity Maximum attendee capacity.
     */
    SafetyBriefing(
        const std::string& name,
        int capacity);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    /**
     * @brief Extends the briefing after a safety alert.
     */
    void onSafetyAlert() override;

    /**
     * @brief Updates the briefing capacity.
     *
     * @param newCapacity New attendee capacity.
     */
    void onCapacityUpdate(int newCapacity) override;

    /**
     * @brief Extends the briefing after a laboratory capacity alert.
     */
    void onSafetyBriefingReminder() override;
};


/**
 * @brief Represents a laboratory demonstration.
 */
class LaboratoryDemonstration : public EventLeaf
{
private:
    std::string name;
    int capacity;
    bool experimentRunning;
    bool equipmentLocked;

public:
    /**
     * @brief Constructs a laboratory demonstration.
     *
     * @param name Name of the demonstration.
     * @param capacity Maximum capacity.
     */
    LaboratoryDemonstration(
        const std::string& name,
        int capacity);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    /**
     * @brief Stops the experiment and locks the equipment.
     */
    void onEmergencyAlert() override;

    /**
     * @brief Responds when the laboratory reaches capacity.
     */
    void onCapacityAlert() override;
};


/**
 * @brief Represents a food vendor at the event.
 */
class FoodVendor : public EventLeaf
{
private:
    std::string name;
    int capacity;
    bool serving;
    std::set<std::string> dietaryOptions;

public:
    /**
     * @brief Constructs a food vendor.
     *
     * @param name Name of the vendor.
     * @param capacity Vendor capacity.
     * @param dietaryOptions Dietary options supported by the vendor.
     */
    FoodVendor(
        const std::string& name,
        int capacity,
        const std::set<std::string>& dietaryOptions);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    void onVenueClosure() override;
    void onWeatherAlert() override;
    void onEmergencyAlert() override;

    /**
     * @brief Responds to a dietary or allergen alert.
     *
     * @param dietaryTag Dietary or allergen tag being checked.
     */
    void onAllergenAlert(
        const std::string& dietaryTag) override;
};


/**
 * @brief Represents a course presentation.
 */
class CoursePresentation : public EventLeaf
{
private:
    std::string name;
    int capacity;
    std::string currentRoom;

public:
    /**
     * @brief Constructs a course presentation.
     *
     * @param name Name of the presentation.
     * @param capacity Presentation capacity.
     * @param room Initial presentation room.
     */
    CoursePresentation(
        const std::string& name,
        int capacity,
        const std::string& room);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    /**
     * @brief Moves the presentation to another room.
     *
     * @param newRoom New presentation room.
     */
    void onRoomChange(
        const std::string& newRoom) override;

    /**
     * @brief Updates the presentation capacity.
     *
     * @param newCapacity New capacity.
     */
    void onCapacityUpdate(
        int newCapacity) override;
};


/**
 * @brief Coordinates the deployment of event shuttles.
 */
class TransportCoordinator : public EventLeaf
{
private:
    std::string name;
    int shuttlesDeployed;

public:
    /**
     * @brief Constructs a transport coordinator.
     *
     * @param name Name of the coordinator.
     * @param initialShuttles Initial number of deployed shuttles.
     */
    TransportCoordinator(
        const std::string& name,
        int initialShuttles);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    void onShuttleOverload() override;
    void onWeatherAlert() override;
};


/**
 * @brief Represents a registration desk.
 */
class RegistrationDesk : public EventLeaf
{
private:
    std::string name;
    int capacity;
    std::string currentRoom;
    bool isOpen;

public:
    /**
     * @brief Constructs a registration desk.
     *
     * @param name Name of the desk.
     * @param capacity Registration capacity.
     * @param room Initial room displayed by the desk.
     */
    RegistrationDesk(
        const std::string& name,
        int capacity,
        const std::string& room);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    void onVenueClosure() override;

    /**
     * @brief Updates the room displayed by the desk.
     *
     * @param newRoom New room.
     */
    void onRoomChange(
        const std::string& newRoom) override;
};


/**
 * @brief Represents a shuttle stop.
 */
class ShuttleStop : public EventLeaf
{
private:
    std::string name;
    int capacity;
    bool suspended;
    bool departuresOnly;

public:
    /**
     * @brief Constructs a shuttle stop.
     *
     * @param name Name of the shuttle stop.
     * @param capacity Shuttle stop capacity.
     */
    ShuttleStop(
        const std::string& name,
        int capacity);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    void onShuttleOverload() override;
    void onWeatherAlert() override;
    void onEmergencyAlert() override;
};


/**
 * @brief Represents a student guide responsible for a visitor group.
 */
class StudentGuide : public EventLeaf
{
private:
    std::string name;
    int groupSize;
    bool redirecting;
    bool evacuationMode;

public:
    /**
     * @brief Constructs a student guide.
     *
     * @param name Name of the guide.
     * @param groupSize Number of visitors in the group.
     */
    StudentGuide(
        const std::string& name,
        int groupSize);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    void onSafetyAlert() override;
    void onCongestion() override;
    void onEmergencyAlert() override;

    /**
     * @brief Redirects visitors to a new presentation room.
     *
     * @param newRoom New presentation room.
     */
    void onRoomChange(
        const std::string& newRoom) override;

    /**
     * @brief Redirects a visitor to the correct faculty.
     *
     * @param correctFaculty Correct faculty.
     */
    void onDepartmentMismatch(
        const std::string& correctFaculty) override;
};


/**
 * @brief Provides information and directions to visitors.
 */
class InformationDesk : public EventLeaf
{
private:
    std::string name;
    int capacity;
    bool operational;
    bool evacuationInstructions;

public:
    /**
     * @brief Constructs an information desk.
     *
     * @param name Name of the information desk.
     * @param capacity Desk capacity.
     */
    InformationDesk(
        const std::string& name,
        int capacity);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    /**
     * @brief Responds to an emergency alert.
     */
    void onEmergencyAlert() override;

    /**
     * @brief Redirects a visitor to the correct faculty.
     *
     * @param correctFaculty Correct faculty.
     */
    void onDepartmentMismatch(
        const std::string& correctFaculty) override;
};

#endif