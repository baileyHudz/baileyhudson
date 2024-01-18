// RoomStateObserver.cpp
#include "RoomStateObserver.h"

// Function to update the state of a room
void RoomStateObserver::updateRoomState(const std::string& roomNumber, const std::string& newState) {
    // Display a message indicating the room state change
    std::cout << "Room " << roomNumber << " state changed to: " << newState << std::endl;

    // Update the current state
    currentState = newState;
}

// Function to view and display the current room state
void RoomStateObserver::viewStateChanges() const {
    // Display the current room state
    std::cout << "Current Room State: " << currentState << std::endl;
}
