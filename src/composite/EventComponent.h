#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>

class EventNotice;

/**
 * @brief Common Component interface for the EventFlow Composite hierarchy.
 *
 * Every event area (OpenDay, Faculty, EventZone) and every leaf unit
 * (InformationDesk, ShuttleStop, etc.) implements this interface, so a
 * client can open/close/query any part of the event tree uniformly
 * without knowing whether it holds a single unit or an entire subtree.
 */
class EventComponent {
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void reportStatus() const = 0;
    virtual int getCapacity() const = 0;

    /**
     * @brief Receives a notice cascading down from an observing ancestor
     * and reacts to it. Concrete leaves react individually (per Task 4.1's
     * differentiated-response requirement); concrete composites recurse
     * this call into their own children so the notice keeps cascading.
     *
     * @param notice The notice being propagated. Not owned by the
     * receiver - it is only valid for the duration of this call.
     */
    virtual void handleNotice(EventNotice* notice) = 0;

    /**
     * @brief Optional reaction hooks, called via double dispatch from a
     * concrete EventNotice's affect(). Default to no-op so a concrete
     * leaf only needs to override the ones it actually cares about -
     * this is how Task 4.1's "different concrete units react differently
     * to the same notice" is achieved without any type-checking: the
     * notice calls affect(this), affect() calls the relevant onX() hook,
     * and virtual dispatch picks the right override for that leaf.
     */
    virtual void onCapacityUpdate(int newCapacity) { (void)newCapacity; }
    virtual void onVenueClosure() {}
    virtual void onRoomChange(const std::string& newRoom) { (void)newRoom; }
    virtual void onSafetyAlert() {}
    virtual void onWeatherAlert() {}
    virtual void onCongestion() {}
    virtual void onShuttleOverload() {}

    virtual ~EventComponent() {}
};

#endif
