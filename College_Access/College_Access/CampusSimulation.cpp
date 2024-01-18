// CampusSimulation.cpp
#include "CampusSimulation.h"

// Function to run the simulation
void CampusSimulation::runSimulation() {
    char choice;

    do {
        // Display menu options
        std::cout << "1. Enter Room Information" << std::endl;
        std::cout << "2. Enter User Information" << std::endl;
        std::cout << "3. Change Room State" << std::endl;
        std::cout << "4. Grant/Deny Access to Room" << std::endl;
        std::cout << "0. Exit" << std::endl;

        // User input
        std::cout << "Enter your choice:\n ";
        std::cin >> choice;

        // Handle user choice
        switch (choice) {
        case '1':
            enterRoomInformation();
            break;
        case '2':
            enterUserInformation();
            break;
        case '3':
            changeRoomState();
            break;
        case '4':
            grantDenyAccess();
            break;
        case '0':
            std::cout << "Exiting the simulation. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '0');
}

// Function to input room information
void CampusSimulation::enterRoomInformation() {
    std::string roomNumber, roomType, roomState;
    std::cout << "Enter the room number: ";
    std::cin >> roomNumber;
    std::cout << "Enter the room type: ";
    std::cin >> roomType;
    std::cout << "Enter the room state (NORMAL or EMERGENCY): ";
    std::cin >> roomState;

    // Store the input
    roomNumbers.push_back(roomNumber);
    roomTypes.push_back(roomType);
    roomStates.push_back(roomState);

    // Print user's input
    std::cout << "Room Information Entered:\n"
        << "Room Number: " << roomNumber << "\n"
        << "Room Type: " << roomType << "\n"
        << "Room State: " << roomState << "\n";
}

// Function to input user information
void CampusSimulation::enterUserInformation() {
    std::string username, usertype;
    std::cout << "Enter the username: ";
    std::cin >> username;
    std::cout << "Enter the user type: ";
    std::cin >> usertype;

    // Store the input
    usernames.push_back(username);
    userTypes.push_back(usertype);

    // Print user's input
    std::cout << "User Information Entered:\n"
        << "Username: " << username << "\n"
        << "User Type: " << usertype << "\n";
}

void CampusSimulation::changeRoomState() {
    std::string roomNumber, roomState;
    std::cout << "Enter the room number: ";
    std::cin >> roomNumber;
    std::cout << "Enter the new room state (NORMAL or EMERGENCY): ";
    std::cin >> roomState;

    // Update the room state
    auto it = std::find(roomNumbers.begin(), roomNumbers.end(), roomNumber);
    if (it != roomNumbers.end()) {
        size_t index = std::distance(roomNumbers.begin(), it);
        roomStates[index] = roomState;
        std::cout << "Room State Updated:\n"
            << "Room Number: " << roomNumber << "\n"
            << "New Room State: " << roomState << "\n";
    }
    else {
        std::cout << "Room not found.\n";
    }
}

// Function to grant or deny access to a user
void CampusSimulation::grantDenyAccess() {
    std::string  usertype, username, roomNumber, accessDecision;
    std::cout << "Enter the room number: ";
    std::cin >> roomNumber;
    std::cout << "Enter the user name: ";
    std::cin >> username;
    std::cout << "Enter the user type: ";
    std::cin >> usertype;
    std::cout << "Enter access decision (GRANTED or DENIED): ";
    std::cin >> accessDecision;

    // Print user's input
    std::cout << "Access to Room " << roomNumber << " is " << accessDecision << "\n";
}
