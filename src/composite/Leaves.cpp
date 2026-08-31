/**
 * @file Leaves.cpp
 * @brief Implements the leaf components used by EventFlow.
 */

#include "Leaves.h"
#include "../observer/EventNotice.h"

#include <iostream>

SafetyBriefing::SafetyBriefing(
    const std::string& n,
    int cap)
    : name(n),
      capacity(cap),
      extended(false)
{
}

void SafetyBriefing::open()
{
    extended = false;
}

void SafetyBriefing::close()
{
}

void SafetyBriefing::reportStatus() const
{
    std::cout << name
              << " [Safety Briefing] - capacity "
              << capacity
              << (extended ? ", session extended" : "")
              << "\n";
}

int SafetyBriefing::getCapacity() const
{
    return capacity;
}

void SafetyBriefing::handleNotice(EventNotice* notice)
{
    if (notice != nullptr)
    {
        notice->affect(this);
    }
}

void SafetyBriefing::onSafetyAlert()
{
    extended = true;

    std::cout << name
              << " extends the session to cover the new alert.\n";
}

void SafetyBriefing::onCapacityUpdate(int newCapacity)
{
    capacity = newCapacity;

    std::cout << name
              << " adjusts attendee limit to "
              << capacity
              << ".\n";
}

void SafetyBriefing::onSafetyBriefingReminder()
{
    extended = true;

    std::cout << name
              << " reminder triggered for laboratory capacity.\n";
}

LaboratoryDemonstration::LaboratoryDemonstration(
    const std::string& n,
    int cap)
    : name(n),
      capacity(cap),
      experimentRunning(false),
      equipmentLocked(false)
{
}

void LaboratoryDemonstration::open()
{
    experimentRunning = true;
    equipmentLocked = false;
}

void LaboratoryDemonstration::close()
{
    experimentRunning = false;
    equipmentLocked = true;
}

void LaboratoryDemonstration::reportStatus() const
{
    std::cout << name
              << " [Laboratory Demonstration] - "
              << (experimentRunning
                      ? "experiment running"
                      : "experiment halted")
              << ", "
              << (equipmentLocked
                      ? "equipment locked"
                      : "equipment unlocked")
              << ", capacity "
              << capacity
              << "\n";
}

int LaboratoryDemonstration::getCapacity() const
{
    return capacity;
}

void LaboratoryDemonstration::handleNotice(
    EventNotice* notice)
{
    if (notice != nullptr)
    {
        notice->affect(this);
    }
}

void LaboratoryDemonstration::onEmergencyAlert()
{
    experimentRunning = false;
    equipmentLocked = true;

    std::cout << name
              << " halts the experiment and locks down equipment.\n";
}

void LaboratoryDemonstration::onCapacityAlert()
{
    std::cout << name
              << " has reached capacity. "
              << "SafetyBriefing reminder triggered.\n";
}

FoodVendor::FoodVendor(
    const std::string& n,
    int cap,
    const std::set<std::string>& options)
    : name(n),
      capacity(cap),
      serving(true),
      dietaryOptions(options)
{
}

void FoodVendor::open()
{
    serving = true;
}

void FoodVendor::close()
{
    serving = false;
}

void FoodVendor::reportStatus() const
{
    std::cout << name
              << " [Food Vendor] - "
              << (serving ? "serving" : "closed")
              << ", capacity "
              << capacity
              << "\n";
}

int FoodVendor::getCapacity() const
{
    return capacity;
}

void FoodVendor::handleNotice(EventNotice* notice)
{
    if (notice != nullptr)
    {
        notice->affect(this);
    }
}

void FoodVendor::onVenueClosure()
{
    serving = false;

    std::cout << name
              << " stops serving - venue closed.\n";
}

void FoodVendor::onWeatherAlert()
{
    serving = false;

    std::cout << name
              << " closes the stall due to weather.\n";
}

void FoodVendor::onEmergencyAlert()
{
    serving = false;

    std::cout << name
              << " closes the stall and halts transactions.\n";
}

void FoodVendor::onAllergenAlert(
    const std::string& dietaryTag)
{
    if (dietaryOptions.find(dietaryTag)
        != dietaryOptions.end())
    {
        std::cout << name
                  << " reacts to the "
                  << dietaryTag
                  << " allergen alert.\n";

        serving = false;
    }
}

CoursePresentation::CoursePresentation(
    const std::string& n,
    int cap,
    const std::string& room)
    : name(n),
      capacity(cap),
      currentRoom(room)
{
}

void CoursePresentation::open()
{
}

void CoursePresentation::close()
{
}

void CoursePresentation::reportStatus() const
{
    std::cout << name
              << " [Course Presentation] - room "
              << currentRoom
              << ", capacity "
              << capacity
              << "\n";
}

int CoursePresentation::getCapacity() const
{
    return capacity;
}

void CoursePresentation::handleNotice(
    EventNotice* notice)
{
    if (notice != nullptr)
    {
        notice->affect(this);
    }
}

void CoursePresentation::onRoomChange(
    const std::string& newRoom)
{
    currentRoom = newRoom;

    std::cout << name
              << " relocates to "
              << currentRoom
              << ".\n";
}

void CoursePresentation::onCapacityUpdate(
    int newCapacity)
{
    capacity = newCapacity;

    std::cout << name
              << " adjusts seating to "
              << capacity
              << ".\n";
}

TransportCoordinator::TransportCoordinator(
    const std::string& n,
    int initial)
    : name(n),
      shuttlesDeployed(initial)
{
}

void TransportCoordinator::open()
{
}

void TransportCoordinator::close()
{
}

void TransportCoordinator::reportStatus() const
{
    std::cout << name
              << " [Transport Coordinator] - "
              << shuttlesDeployed
              << " shuttles deployed\n";
}

int TransportCoordinator::getCapacity() const
{
    return shuttlesDeployed;
}

void TransportCoordinator::handleNotice(
    EventNotice* notice)
{
    if (notice != nullptr)
    {
        notice->affect(this);
    }
}

void TransportCoordinator::onShuttleOverload()
{
    shuttlesDeployed += 2;

    std::cout << name
              << " deploys 2 more shuttles - now "
              << shuttlesDeployed
              << ".\n";
}

void TransportCoordinator::onWeatherAlert()
{
    std::cout << name
              << " adjusts routes for weather conditions.\n";
}

RegistrationDesk::RegistrationDesk(
    const std::string& n,
    int cap,
    const std::string& room)
    : name(n),
      capacity(cap),
      currentRoom(room),
      isOpen(true)
{
}

void RegistrationDesk::open()
{
    isOpen = true;
}

void RegistrationDesk::close()
{
    isOpen = false;
}

void RegistrationDesk::reportStatus() const
{
    std::cout << name
              << " [Registration] - room "
              << currentRoom
              << ", "
              << (isOpen ? "open" : "closed")
              << ", capacity "
              << capacity
              << "\n";
}

int RegistrationDesk::getCapacity() const
{
    return capacity;
}

void RegistrationDesk::handleNotice(
    EventNotice* notice)
{
    if (notice != nullptr)
    {
        notice->affect(this);
    }
}

void RegistrationDesk::onVenueClosure()
{
    isOpen = false;

    std::cout << name
              << " stops accepting registrations - venue closed.\n";
}

void RegistrationDesk::onRoomChange(
    const std::string& newRoom)
{
    currentRoom = newRoom;

    std::cout << name
              << " updates its displayed room to "
              << currentRoom
              << ".\n";
}

ShuttleStop::ShuttleStop(
    const std::string& n,
    int cap)
    : name(n),
      capacity(cap),
      suspended(false),
      departuresOnly(false)
{
}

void ShuttleStop::open()
{
    suspended = false;
    departuresOnly = false;
}

void ShuttleStop::close()
{
    suspended = true;
}

void ShuttleStop::reportStatus() const
{
    std::cout << name
              << " [Shuttle Stop] - "
              << (suspended ? "SUSPENDED" : "running");

    if (departuresOnly)
    {
        std::cout << ", departures only";
    }

    std::cout << ", capacity "
              << capacity
              << "\n";
}

int ShuttleStop::getCapacity() const
{
    return capacity;
}

void ShuttleStop::handleNotice(
    EventNotice* notice)
{
    if (notice != nullptr)
    {
        notice->affect(this);
    }
}

void ShuttleStop::onShuttleOverload()
{
    capacity += 10;

    std::cout << name
              << " adds an extra shuttle - capacity now "
              << capacity
              << ".\n";
}

void ShuttleStop::onWeatherAlert()
{
    suspended = true;

    std::cout << name
              << " suspends service due to weather.\n";
}

void ShuttleStop::onEmergencyAlert()
{
    suspended = true;
    departuresOnly = true;

    std::cout << name
              << " suspends drop-offs and allows departures only.\n";
}

StudentGuide::StudentGuide(
    const std::string& n,
    int size)
    : name(n),
      groupSize(size),
      redirecting(false),
      evacuationMode(false)
{
}

void StudentGuide::open()
{
    redirecting = false;
    evacuationMode = false;
}

void StudentGuide::close()
{
    redirecting = false;
    evacuationMode = false;
}

void StudentGuide::reportStatus() const
{
    std::cout << name
              << " [Student Guide] - group of "
              << groupSize;

    if (evacuationMode)
    {
        std::cout << ", EVACUATION MODE";
    }
    else if (redirecting)
    {
        std::cout << ", currently redirecting visitors";
    }

    std::cout << "\n";
}

int StudentGuide::getCapacity() const
{
    return groupSize;
}

void StudentGuide::handleNotice(
    EventNotice* notice)
{
    if (notice != nullptr)
    {
        notice->affect(this);
    }
}

void StudentGuide::onSafetyAlert()
{
    redirecting = true;

    std::cout << name
              << " redirects visitors away from the area.\n";
}

void StudentGuide::onCongestion()
{
    redirecting = true;

    std::cout << name
              << " reroutes the group to a less congested area.\n";
}

void StudentGuide::onEmergencyAlert()
{
    evacuationMode = true;
    redirecting = true;

    std::cout << name
              << " switches to evacuation mode and redirects "
              << "visitors to the nearest exit.\n";
}

void StudentGuide::onRoomChange(
    const std::string& newRoom)
{
    redirecting = true;

    std::cout << name
              << " redirects visitors to the new presentation room: "
              << newRoom
              << ".\n";
}

void StudentGuide::onDepartmentMismatch(
    const std::string& correctFaculty)
{
    redirecting = true;

    std::cout << name
              << " redirects the visitor to the "
              << correctFaculty
              << " faculty.\n";
}

InformationDesk::InformationDesk(
    const std::string& n,
    int cap)
    : name(n),
      capacity(cap),
      operational(true),
      evacuationInstructions(false)
{
}

void InformationDesk::open()
{
    operational = true;
    evacuationInstructions = false;
}

void InformationDesk::close()
{
    operational = false;
}

void InformationDesk::reportStatus() const
{
    std::cout << name
              << " [Information Desk] - "
              << (operational ? "operational" : "closed");

    if (evacuationInstructions)
    {
        std::cout << ", displaying evacuation instructions";
    }

    std::cout << ", capacity "
              << capacity
              << "\n";
}

int InformationDesk::getCapacity() const
{
    return capacity;
}

void InformationDesk::handleNotice(
    EventNotice* notice)
{
    if (notice != nullptr)
    {
        notice->affect(this);
    }
}

void InformationDesk::onEmergencyAlert()
{
    operational = true;
    evacuationInstructions = true;

    std::cout << name
              << " remains operational and displays evacuation "
              << "instructions.\n";
}

void InformationDesk::onDepartmentMismatch(
    const std::string& correctFaculty)
{
    std::cout << name
              << " redirects the visitor to the "
              << correctFaculty
              << " faculty.\n";
}