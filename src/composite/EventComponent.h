#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>

class EventNotice;

/**
 * @brief Base interface for all components in the EventFlow system.
 *
 * EventComponent is the common interface used by both composite
 * groups and leaf components.
 */
class EventComponent
{
public:
    /**
     * @brief Opens the component.
     */
    virtual void open() = 0;

    /**
     * @brief Closes the component.
     */
    virtual void close() = 0;

    /**
     * @brief Displays the current status of the component.
     */
    virtual void reportStatus() const = 0;

    /**
     * @brief Returns the capacity associated with the component.
     *
     * @return Component capacity.
     */
    virtual int getCapacity() const = 0;

    /**
     * @brief Handles a notification received by the component.
     *
     * @param notice Notification being received.
     */
    virtual void handleNotice(EventNotice* notice) = 0;

    /**
     * @brief Updates the component's capacity.
     *
     * @param newCapacity New capacity value.
     */
    virtual void onCapacityUpdate(int newCapacity)
    {
        (void)newCapacity;
    }

    /**
     * @brief Handles a venue closure notification.
     */
    virtual void onVenueClosure() {}

    /**
     * @brief Handles a room change notification.
     *
     * @param newRoom New room.
     */
    virtual void onRoomChange(const std::string& newRoom)
    {
        (void)newRoom;
    }

    /**
     * @brief Handles a safety alert.
     */
    virtual void onSafetyAlert() {}

    /**
     * @brief Handles a weather alert.
     */
    virtual void onWeatherAlert() {}

    /**
     * @brief Handles an exhibition congestion notification.
     */
    virtual void onCongestion() {}

    /**
     * @brief Handles a shuttle overload notification.
     */
    virtual void onShuttleOverload() {}

    /**
     * @brief Handles an emergency alert.
     */
    virtual void onEmergencyAlert() {}

    /**
     * @brief Handles a capacity alert.
     */
    virtual void onCapacityAlert() {}

    /**
     * @brief Handles an allergen or dietary alert.
     *
     * @param dietaryTag Dietary or allergen tag associated with the alert.
     */
    virtual void onAllergenAlert(
        const std::string& dietaryTag)
    {
        (void)dietaryTag;
    }

    /**
     * @brief Handles a department mismatch notification.
     *
     * @param correctFaculty Faculty the visitor should be redirected to.
     */
    virtual void onDepartmentMismatch(
        const std::string& correctFaculty)
    {
        (void)correctFaculty;
    }

    /**
     * @brief Handles a safety briefing reminder.
     */
    virtual void onSafetyBriefingReminder() {}

    /**
     * @brief Virtual destructor.
     */
    virtual ~EventComponent() {}
};

#endif