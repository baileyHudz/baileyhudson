// RoomConfiguration.cpp
#include "RoomConfiguration.h"
#include <iostream>
#include <algorithm>

// Function to get the vector of rooms
const std::vector<RoomConfiguration::Room>& RoomConfiguration::getRooms() const {
    return rooms;
}

// Function to display available room types
void RoomConfiguration::displayRoomTypes() const {
    std::cout << "1. Lecture Hall" << std::endl;
    std::cout << "2. Teaching Room" << std::endl;
    std::cout << "3. Staff Room" << std::endl;
    std::cout << "4. Secure Room" << std::endl;
}

// Function to display the list of rooms
void RoomConfiguration::displayRoomList() const {
    if (rooms.empty()) {
        std::cout << "No rooms are currently saved." << std::endl;
    }
    else {
        std::cout << "Room List" << std::endl;
        for (const auto& room : rooms) {
            std::cout << room.roomNumber << " - " << room.roomType << " - State: " << room.roomState << std::endl;
        }
    }
}

// Function to add a new room to the configuration
void RoomConfiguration::addRoom(const std::string& roomNumber, const std::string& roomType, const std::string& roomState) {
    Room newRoom;
    newRoom.roomNumber = roomNumber;
    newRoom.roomType = roomType;
    newRoom.roomState = roomState; // Set the room state
    rooms.push_back(newRoom);
    std::cout << "Room " << roomNumber << " added successfully." << std::endl;

    // Notify observers about the new room and its state
    notifyObservers(roomNumber, roomState);
}

// Function to update an existing room in the configuration
void RoomConfiguration::updateRoom(const std::string& roomNumber, const std::string& newRoomType, const std::string& newRoomState) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNumber](const Room& room) {
        return room.roomNumber == roomNumber;
        });

    if (it != rooms.end()) {
        it->roomType = newRoomType;
        it->roomState = newRoomState;
        std::cout << "Room " << roomNumber << " updated successfully." << std::endl;
        // Notify observers about the updated room and its state
        notifyObservers(roomNumber, newRoomState);
    }
    else {
        std::cout << "Room not found. Unable to update." << std::endl;
    }
}

// Function to remove a room from the configuration
void RoomConfiguration::removeRoom(const std::string& roomNumber) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNumber](const Room& room) {
        return room.roomNumber == roomNumber;
        });

    if (it != rooms.end()) {
        rooms.erase(it);
        std::cout << "Room " << roomNumber << " removed successfully." << std::endl;
        // Notify observers about the removed room
        notifyObservers(roomNumber, "");
    }
    else {
        std::cout << "Room not found. Unable to remove." << std::endl;
    }
}

// Function to display the room configuration menu
void RoomConfiguration::roomConfigurationMenu() {
    char roomsMenuChoice;

    do {
        std::cout << "1. Display Room Types" << std::endl;
        std::cout << "2. Display Room List" << std::endl;
        std::cout << "3. Add Room" << std::endl;
        std::cout << "4. Update Room" << std::endl;
        std::cout << "5. Remove Room" << std::endl;
        std::cout << "0. Go Back to Main Menu" << std::endl;

        std::cout << "Enter your choice:\n ";
        std::cin >> roomsMenuChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (roomsMenuChoice) {
        case '1':
            displayRoomTypes();
            break;
        case '2':
            displayRoomList();
            break;
        case '3':
        {
            std::string roomNumber, roomType, roomState;
            std::cout << "Enter the new room number: ";
            std::cin >> roomNumber;
            std::cout << "Enter the room type: ";
            std::cin >> roomType;
            std::cout << "Enter the room state (NORMAL or EMERGENCY): ";
            std::cin >> roomState;
            addRoom(roomNumber, roomType, roomState);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        break;
        case '4':
        {
            std::string roomNumber, newRoomType, newRoomState;
            std::cout << "Enter the room number to update: ";
            std::cin >> roomNumber;
            std::cout << "Enter the new room type: ";
            std::cin >> newRoomType;
            std::cout << "Enter the new room state (NORMAL or EMERGENCY): ";
            std::cin >> newRoomState;
            updateRoom(roomNumber, newRoomType, newRoomState);
        }
        break;
        case '5':
        {
            std::string roomNumber;
            std::cout << "Enter the room number to remove: ";
            std::cin >> roomNumber;
            removeRoom(roomNumber);
        }
        break;
        case '0':
            std::cout << "Going back to the Main Menu." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (roomsMenuChoice != '0');
}

// Function to add an observer to the room configuration
void RoomConfiguration::addObserver(RoomObserver* observer) {
    observers.push_back(observer);
}

// Function to notify observers about a room state change
void RoomConfiguration::notifyObservers(const std::string& roomNumber, const std::string& newRoomState) {
    for (const auto& observer : observers) {
        observer->updateRoomState(roomNumber, newRoomState);
    }
}

// Function to get the state of a room given its room number
std::string RoomConfiguration::getRoomState(const std::string& roomNumber) const {
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNumber](const Room& room) {
        return room.roomNumber == roomNumber;
        });

    if (it != rooms.end()) {
        return it->roomState;
    }

    return "";  // Return an empty if room not found
}

// Function to set the state of a room given its room number
void RoomConfiguration::setRoomState(const std::string& roomNumber, const std::string& newState) {
    auto it = std::find_if(rooms.begin(), rooms.end(), [roomNumber](const Room& room) {
        return room.roomNumber == roomNumber;
        });

    if (it != rooms.end()) {
        it->roomState = newState;
    }
}
