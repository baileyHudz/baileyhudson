// AlphabeticalUserList.cpp
#include "AlphabeticalUserList.h"
#include <algorithm>

// Function to compare users based on their usernames for sorting.
bool compareUsernames(const CampusCardUsers::User& a, const CampusCardUsers::User& b) {
    return a.username < b.username;
}

// Constructor taking a reference to Campus Card Users.
AlphabeticalUserList::AlphabeticalUserList(CampusCardUsers& campusCardUsers)
    : campusCardUsers(campusCardUsers) {}

// Displays the list of users alphabetically.
void AlphabeticalUserList::showCurrentUserListAlphabetically() const {
    // Get the reference to the vector of users from Campus Card Users.
    const std::vector<CampusCardUsers::User>& users = campusCardUsers.getUsers();

    // Create a copy of the users and sort them alphabetically.
    std::vector<CampusCardUsers::User> sortedUsersCopy = users;
    std::sort(sortedUsersCopy.begin(), sortedUsersCopy.end(), compareUsernames);

    // Display the sorted user list.
    std::cout << "Current User List Alphabetically" << std::endl;
    for (const auto& user : sortedUsersCopy) {
        std::cout << user.username << " - " << user.userType << std::endl;
    }
}

// Provides a menu for interacting with the alphabetical user list.
void AlphabeticalUserList::alphabeticalUserListMenu() {
    std::cout << "Alphabetical User List" << std::endl;

    // Display the user list alphabetically.
    showCurrentUserListAlphabetically();

    char menuChoice;
    do {
        // Display menu options.
        std::cout << "0. Go Back to Main Menu" << std::endl;
        std::cout << "Enter your choice:\n ";
        std::cin >> menuChoice;

        switch (menuChoice) {
        case '0':
            std::cout << "Going back to the Main Menu." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (menuChoice != '0');
}

