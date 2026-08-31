#include "Leaves.h"
#include "EventNotice.h"
#include <iostream>

// ---- SafetyBriefing ----
SafetyBriefing::SafetyBriefing(const std::string& n, int cap)
    : name(n), capacity(cap), extended(false) {}

void SafetyBriefing::open() { extended = false; }
void SafetyBriefing::close() {}

void SafetyBriefing::reportStatus() const {
    std::cout << name << " [Safety Briefing] - capacity " << capacity
              << (extended ? ", session extended" : "") << "\n";
}

int SafetyBriefing::getCapacity() const { return capacity; }

void SafetyBriefing::handleNotice(EventNotice* notice) {
    notice->affect(this);
}

void SafetyBriefing::onSafetyAlert() {
    extended = true;
    std::cout << name << " extends the session to cover the new alert.\n";
}

void SafetyBriefing::onCapacityUpdate(int newCapacity) {
    capacity = newCapacity;
    std::cout << name << " adjusts attendee limit to " << capacity << ".\n";
}

// ---- FoodVendor ----
FoodVendor::FoodVendor(const std::string& n, int cap)
    : name(n), capacity(cap), serving(true) {}

void FoodVendor::open() { serving = true; }
void FoodVendor::close() { serving = false; }

void FoodVendor::reportStatus() const {
    std::cout << name << " [Food Vendor] - " << (serving ? "serving" : "closed")
              << ", capacity " << capacity << "\n";
}

int FoodVendor::getCapacity() const { return capacity; }

void FoodVendor::handleNotice(EventNotice* notice) {
    notice->affect(this);
}

void FoodVendor::onVenueClosure() {
    serving = false;
    std::cout << name << " stops serving - venue closed.\n";
}

void FoodVendor::onWeatherAlert() {
    serving = false;
    std::cout << name << " closes the stall due to weather.\n";
}

// ---- CoursePresentation ----
CoursePresentation::CoursePresentation(const std::string& n, int cap, const std::string& room)
    : name(n), capacity(cap), currentRoom(room) {}

void CoursePresentation::open() {}
void CoursePresentation::close() {}

void CoursePresentation::reportStatus() const {
    std::cout << name << " [Course Presentation] - room " << currentRoom
              << ", capacity " << capacity << "\n";
}

int CoursePresentation::getCapacity() const { return capacity; }

void CoursePresentation::handleNotice(EventNotice* notice) {
    notice->affect(this);
}

void CoursePresentation::onRoomChange(const std::string& newRoom) {
    currentRoom = newRoom;
    std::cout << name << " relocates to " << currentRoom << ".\n";
}

void CoursePresentation::onCapacityUpdate(int newCapacity) {
    capacity = newCapacity;
    std::cout << name << " adjusts seating to " << capacity << ".\n";
}

// ---- TransportCoordinator ----
TransportCoordinator::TransportCoordinator(const std::string& n, int initial)
    : name(n), shuttlesDeployed(initial) {}

void TransportCoordinator::open() {}
void TransportCoordinator::close() {}

void TransportCoordinator::reportStatus() const {
    std::cout << name << " [Transport Coordinator] - " << shuttlesDeployed << " shuttles deployed\n";
}

int TransportCoordinator::getCapacity() const { return shuttlesDeployed; }

void TransportCoordinator::handleNotice(EventNotice* notice) {
    notice->affect(this);
}

void TransportCoordinator::onShuttleOverload() {
    shuttlesDeployed += 2;
    std::cout << name << " deploys 2 more shuttles - now " << shuttlesDeployed << ".\n";
}

void TransportCoordinator::onWeatherAlert() {
    std::cout << name << " adjusts routes for weather conditions.\n";
}

// ---- RegistrationDesk ----
RegistrationDesk::RegistrationDesk(const std::string& n, int cap, const std::string& room)
    : name(n), capacity(cap), currentRoom(room), isOpen(true) {}
 
void RegistrationDesk::open() { isOpen = true; }
void RegistrationDesk::close() { isOpen = false; }
 
void RegistrationDesk::reportStatus() const {
    std::cout << name << " [Registration] - room " << currentRoom << ", "
              << (isOpen ? "open" : "closed") << ", capacity " << capacity << "\n";
}
 
int RegistrationDesk::getCapacity() const { return capacity; }
 
void RegistrationDesk::handleNotice(EventNotice* notice) {
    notice->affect(this);
}
 
void RegistrationDesk::onVenueClosure() {
    isOpen = false;
    std::cout << name << " stops accepting registrations - venue closed.\n";
}
 
void RegistrationDesk::onRoomChange(const std::string& newRoom) {
    currentRoom = newRoom;
    std::cout << name << " updates its displayed room to " << currentRoom << ".\n";
}
 
// ---- ShuttleStop ----
ShuttleStop::ShuttleStop(const std::string& n, int cap)
    : name(n), capacity(cap), suspended(false) {}
 
void ShuttleStop::open() { suspended = false; }
void ShuttleStop::close() { suspended = true; }
 
void ShuttleStop::reportStatus() const {
    std::cout << name << " [Shuttle Stop] - " << (suspended ? "SUSPENDED" : "running")
              << ", capacity " << capacity << "\n";
}
 
int ShuttleStop::getCapacity() const { return capacity; }
 
void ShuttleStop::handleNotice(EventNotice* notice) {
    notice->affect(this);
}
 
void ShuttleStop::onShuttleOverload() {
    capacity += 10;
    std::cout << name << " adds an extra shuttle - capacity now " << capacity << ".\n";
}
 
void ShuttleStop::onWeatherAlert() {
    suspended = true;
    std::cout << name << " suspends service due to weather.\n";
}
 
// ---- StudentGuide ----
StudentGuide::StudentGuide(const std::string& n, int size)
    : name(n), groupSize(size), redirecting(false) {}
 
void StudentGuide::open() { redirecting = false; }
void StudentGuide::close() { redirecting = false; }
 
void StudentGuide::reportStatus() const {
    std::cout << name << " [Student Guide] - group of " << groupSize
              << (redirecting ? ", currently redirecting visitors" : "") << "\n";
}
 
int StudentGuide::getCapacity() const { return groupSize; }
 
void StudentGuide::handleNotice(EventNotice* notice) {
    notice->affect(this);
}
 
void StudentGuide::onSafetyAlert() {
    redirecting = true;
    std::cout << name << " redirects visitors away from the area.\n";
}
 
void StudentGuide::onCongestion() {
    redirecting = true;
    std::cout << name << " reroutes the group to a less congested area.\n";
}
