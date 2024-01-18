#include <iostream>
#include "RoomConfiguration.h"
#include "CampusCardUsers.h"
#include "AlphabeticalUserList.h"
#include "RoomStateObserver.h"
#include "RoomObserver.h"
#include "CampusSimulation.h"
#include "Logs.h" 

using namespace std;

int main() {
    char choice;

    // Create instances of the required classes
    CampusCardUsers campusCardUsers;
    AlphabeticalUserList alphabeticalUserList(campusCardUsers);
    RoomConfiguration roomConfig;
    RoomStateObserver stateObserver;
    roomConfig.addObserver(&stateObserver);
    CampusSimulation campusSimulation;

    do {
        // Display menu
        cout << "1. Alphabetical User List" << endl;
        cout << "2. Campus Card Users" << endl;
        cout << "3. Campus Simulation" << endl; 
        cout << "4. Room Configuration" << endl;
        cout << "Exit" << endl;

        // User input
        cout << "Enter your choice:\n ";
        std::cin >> choice;

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Handle user choice
        if (std::cin.fail()) {
            std::cin.clear(); // clear input buffer to restore cin to a usable state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the bad input
            std::cout << "Invalid input. Please enter a valid option." << std::endl;
        }
        else {
            switch (choice) {
            case '1':
                alphabeticalUserList.alphabeticalUserListMenu();
                break;
            case '2':
                campusCardUsers.campusCardUsersMenu();
                break;
            case '3':
                campusSimulation.runSimulation(); // Run the CampusSimulation
                break;
            case '4':
                roomConfig.roomConfigurationMenu();
                break;
            case 'e':
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    } while (choice != 'e');

    // Save data before exiting
    Logs::saveData(campusCardUsers, roomConfig, "Daily_Logs.txt");

    stateObserver.viewStateChanges();

    return 0;
}
