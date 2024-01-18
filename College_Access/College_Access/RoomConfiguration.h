// RoomConfiguration.h
#ifndef ROOMCONFIGURATION_H
#define ROOMCONFIGURATION_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include "RoomObserver.h"

class RoomConfiguration {
public:
    struct Room {
        std::string roomNumber;
        std::string roomType;
        std::string roomState; // New field to store room state
    };

protected:
    std::vector<Room> rooms; // Vector to store room information
    std::vector<RoomObserver*> observers;// Vector to store room observers

public:
    void displayRoomTypes() const;
    void displayRoomList() const;
    void addRoom(const std::string& roomNumber, const std::string& roomType, const std::string& roomState = "NORMAL");
    void updateRoom(const std::string& roomNumber, const std::string& newRoomType, const std::string& newRoomState);
    void removeRoom(const std::string& roomNumber);
    const std::vector<Room>& getRooms() const;
    void roomConfigurationMenu();

    void addObserver(RoomObserver* observer);
    void notifyObservers(const std::string& roomNumber, const std::string& newState);
    std::string getRoomState(const std::string& roomNumber) const; // New function to get room state

private:
    void setRoomState(const std::string& roomNumber, const std::string& newState);
};

#endif 
