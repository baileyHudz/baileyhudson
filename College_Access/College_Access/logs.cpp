// Logs.cpp

#include "Logs.h"

// Function to save data to a specified file
void Logs::saveData(const CampusCardUsers& campusCardUsers, const RoomConfiguration& roomConfig, const std::string& filename) {
    // Open the output file for writing
    std::ofstream outputFile(filename);

    // Save users information
    const auto& users = campusCardUsers.getUsers();
    for (const auto& user : users) {
        outputFile << "User: " << user.username << " - " << user.userType << std::endl;
    }

    // Save rooms information
    const auto& rooms = roomConfig.getRooms();
    for (const auto& room : rooms) {
        outputFile << "Room: " << room.roomNumber << " - " << room.roomType << " - State: " << room.roomState << std::endl;
    }

    // Close the output file after writing
    outputFile.close();
}
