#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include <vector>

#include "Subject.h"

class Observer;
class EventNotice;

/**
 * @brief Subject responsible for sending EventFlow notifications.
 */
class EventControl : public Subject
{
private:
    std::vector<Observer*> observers;

public:
    /**
     * @brief Registers an observer.
     *
     * @param observer Observer to attach.
     */
    void attach(Observer* observer) override;

    /**
     * @brief Removes an observer.
     *
     * @param observer Observer to detach.
     */
    void detach(Observer* observer) override;

    /**
     * @brief Sends a notice to all registered observers.
     *
     * @param notice Notice to send.
     */
    void notify(EventNotice* notice) override;
};

#endif