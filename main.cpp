/**
 * @file main.cpp
 * @brief Demonstrates the EventFlow Composite and Observer patterns.
 */

#include <iostream>
#include <set>

#include "src/composite/EventGroup.h"
#include "src/composite/Leaves.h"

#include "src/event/Visitor.h"

#include "src/observer/EventControl.h"
#include "src/observer/EventNotificationHandler.h"

#include "src/observer/EmergencyAlert.h"
#include "src/observer/CapacityAlert.h"
#include "src/observer/AllergenAlert.h"
#include "src/observer/RoomChangeNotice.h"
#include "src/observer/DepartmentMismatch.h"

int main()
{
    std::cout << "============================================\n";
    std::cout << "        EVENTFLOW TASK 4 DEMONSTRATION\n";
    std::cout << "============================================\n\n";

    // Build the EventFlow structure.

    OpenDay openDay("University Open Day");

    Faculty scienceFaculty("Faculty of Science");
    Faculty engineeringFaculty("Faculty of Engineering");

    ExhibitionZone scienceExhibition(
        "Science Exhibition",
        100);

    ExhibitionZone engineeringExhibition(
        "Engineering Exhibition",
        100);

    EventZone laboratory(
        "Science Laboratory",
        30,
        true);

    EventZone registrationZone(
        "Registration Zone",
        50);

    CampusServices campusServices(
        "Campus Services");

    LaboratoryDemonstration laboratoryDemo(
        "Chemistry Laboratory Demonstration",
        30);

    SafetyBriefing safetyBriefing(
        "Laboratory Safety Briefing",
        30);

    StudentGuide scienceGuide(
        "Science Student Guide",
        10);

    StudentGuide engineeringGuide(
        "Engineering Student Guide",
        10);

    InformationDesk informationDesk(
        "Main Information Desk",
        20);

    ShuttleStop shuttleStop(
        "Main Shuttle Stop",
        40);

    FoodVendor foodVendor(
        "Campus Food Stall",
        50,
        std::set<std::string>{
            "vegetarian",
            "halal",
            "allergen-free"
        });

    CoursePresentation coursePresentation(
        "Computer Science Presentation",
        40,
        "Room A");

    RegistrationDesk registrationDesk(
        "Science Registration Desk",
        20,
        "Room A");

    TransportCoordinator transportCoordinator(
        "Campus Transport",
        5);

    laboratory.add(&laboratoryDemo);
    laboratory.add(&safetyBriefing);

    scienceExhibition.add(&scienceGuide);

    engineeringExhibition.add(&engineeringGuide);

    registrationZone.add(&coursePresentation);
    registrationZone.add(&registrationDesk);

    scienceFaculty.add(&scienceExhibition);
    scienceFaculty.add(&laboratory);

    engineeringFaculty.add(&engineeringExhibition);
    engineeringFaculty.add(&registrationZone);

    campusServices.add(&informationDesk);
    campusServices.add(&shuttleStop);
    campusServices.add(&foodVendor);
    campusServices.add(&transportCoordinator);

    openDay.add(&scienceFaculty);
    openDay.add(&engineeringFaculty);
    openDay.add(&campusServices);

    // Open the event and display its initial state.

    std::cout << "========== OPEN DAY STATUS ==========\n";

    openDay.open();
    openDay.reportStatus();

    std::cout << "\n";

    // Set up the Observer relationship.

    EventControl eventControl;
    EventNotificationHandler eventHandler(&openDay);

    eventControl.attach(&eventHandler);

    // Task 4.1: Emergency alert.

    std::cout << "\n";
    std::cout << "========== TASK 4.1 ==========\n";
    std::cout << "Five different reactions to the same\n";
    std::cout << "EMERGENCY_ALERT\n";
    std::cout << "========================================\n";

    EmergencyAlert emergency(
        "Emergency evacuation required.",
        "University Open Day");

    eventControl.notify(&emergency);

    // Task 4.3: Capacity threshold.

    std::cout << "\n";
    std::cout << "========== TASK 4.3 ==========\n";
    std::cout << "Capacity threshold demonstration\n";
    std::cout << "========================================\n";

    Visitor visitor1(
        "Visitor 1",
        "Science");

    Visitor visitor2(
        "Visitor 2",
        "Science");

    laboratory.admitVisitor(visitor1);

    for (int i = laboratory.getVisitorCount();
         i < laboratory.getCapacityLimit();
         ++i)
    {
        Visitor visitor(
            "Laboratory Visitor " + std::to_string(i + 1),
            "Science");

        laboratory.admitVisitor(visitor);
    }

    laboratory.admitVisitor(visitor2);

    // Task 4.4.1: Room change.

    std::cout << "\n";
    std::cout << "========== TASK 4.4.1 ==========\n";
    std::cout << "Course presentation room change\n";
    std::cout << "========================================\n";

    RoomChangeNotice roomChange(
        "Course presentation venue changed.",
        "Room A",
        "Room B");

    eventControl.notify(&roomChange);

    // Task 4.4.2: Dietary requirements.

    std::cout << "\n";
    std::cout << "========== TASK 4.4.2 ==========\n";
    std::cout << "Dietary / allergen alert\n";
    std::cout << "========================================\n";

    AllergenAlert halalAlert(
        "This food contains an undeclared allergen.",
        "Campus Food Stall",
        "halal");

    eventControl.notify(&halalAlert);

    // Task 4.4.3: Department mismatch.

    std::cout << "\n";
    std::cout << "========== TASK 4.4.3 ==========\n";
    std::cout << "Department mismatch\n";
    std::cout << "========================================\n";

    DepartmentMismatch departmentMismatch(
        "Visitor is in the wrong faculty.",
        "Engineering Exhibition",
        "Science");

    eventControl.notify(&departmentMismatch);

    // Task 4.2: Faculty congestion and guide movement.

    std::cout << "\n";
    std::cout << "========== TASK 4.2 ==========\n";
    std::cout << "Faculty congestion and runtime\n";
    std::cout << "StudentGuide reorganization\n";
    std::cout << "========================================\n";

    for (int i = 0;
         i < 90;
         ++i)
    {
        Visitor visitor(
            "Engineering Visitor " + std::to_string(i + 1),
            "Engineering");

        engineeringExhibition.admitVisitor(visitor);
    }

    EventNotificationHandler guideHandler(&scienceGuide);

    if (engineeringExhibition.isCongested())
    {
        std::cout
            << "Engineering Exhibition is congested.\n";

        scienceExhibition.attach(&guideHandler);

        scienceExhibition.moveGuide(
            &scienceGuide,
            &engineeringExhibition,
            &guideHandler);
    }

    // Verify that the guide now observes the new zone.

    std::cout << "\n";
    std::cout << "========== OBSERVER REORGANIZATION ==========\n";
    std::cout << "Testing the StudentGuide after movement\n";
    std::cout << "==============================================\n";

    EmergencyAlert movementTest(
        "Emergency after guide movement.",
        "Engineering Exhibition");

    std::cout << "\nNotice from the NEW zone:\n";

    engineeringExhibition.notify(&movementTest);

    std::cout << "\nNotice from the OLD zone:\n";

    scienceExhibition.notify(&movementTest);

    std::cout << "\nObserver reorganization test complete.\n";

    // Display the final state.

    std::cout << "\n";
    std::cout << "========== FINAL EVENT STATUS ==========\n";

    openDay.reportStatus();

    std::cout << "\n============================================\n";
    std::cout << "       EVENTFLOW DEMONSTRATION COMPLETE\n";
    std::cout << "============================================\n";

    return 0;
}