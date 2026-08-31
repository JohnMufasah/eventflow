#ifndef LEAVES_H
#define LEAVES_H

#include "EventLeaf.h"
#include <string>

/// Runs safety briefings - cares about safety alerts (extends the
/// session) and capacity (limits attendees per briefing).
class SafetyBriefing : public EventLeaf {
private:
    std::string name;
    int capacity;
    bool extended;

public:
    SafetyBriefing(const std::string& name, int capacity);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    void onSafetyAlert() override;
    void onCapacityUpdate(int newCapacity) override;
};

/// Sells food - cares about venue closure (stops service) and weather
/// (closes an outdoor stall), ignores safety/capacity notices.
class FoodVendor : public EventLeaf {
private:
    std::string name;
    int capacity;
    bool serving;

public:
    FoodVendor(const std::string& name, int capacity);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    void onVenueClosure() override;
    void onWeatherAlert() override;
};

class CoursePresentation : public EventLeaf {
private:
    std::string name;
    int capacity;
    std::string currentRoom;

public:
    CoursePresentation(const std::string& name, int capacity, const std::string& room);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    void onRoomChange(const std::string& newRoom) override;
    void onCapacityUpdate(int newCapacity) override;
};

class TransportCoordinator : public EventLeaf {
private:
    std::string name;
    int shuttlesDeployed;

public:
    TransportCoordinator(const std::string& name, int initialShuttles);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;

    void onShuttleOverload() override;
    void onWeatherAlert() override;
};

class RegistrationDesk : public EventLeaf {
private:
    std::string name;
    int capacity;
    std::string currentRoom;
    bool isOpen;
 
public:
    RegistrationDesk(const std::string& name, int capacity, const std::string& room);
 
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;
 
    void onVenueClosure() override;
    void onRoomChange(const std::string& newRoom) override;
};
 
class ShuttleStop : public EventLeaf {
private:
    std::string name;
    int capacity;
    bool suspended;
 
public:
    ShuttleStop(const std::string& name, int capacity);
 
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;
 
    void onShuttleOverload() override;
    void onWeatherAlert() override;
};

class StudentGuide : public EventLeaf {
private:
    std::string name;
    int groupSize;
    bool redirecting;
 
public:
    StudentGuide(const std::string& name, int groupSize);
 
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void handleNotice(EventNotice* notice) override;
 
    void onSafetyAlert() override;
    void onCongestion() override;
};

#endif
