// RoomStateObserver.h
#ifndef ROOMSTATEOBSERVER_H
#define ROOMSTATEOBSERVER_H

#include "RoomObserver.h"
#include <iostream>

class RoomStateObserver : public RoomObserver {
public:
    void updateRoomState(const std::string& roomNumber, const std::string& newState) override;
    void viewStateChanges() const;
private:
    std::string currentState;  // Variable to store the current state
};

#endif 