// CampusCardUsers.cpp
#include "CampusCardUsers.h"

// Returns a const reference to the vector of users.
const std::vector<CampusCardUsers::User>& CampusCardUsers::getUsers() const {
    return users;
}

// Displays the types of users available.
void CampusCardUsers::displayUserTypes() const {
    // Prints out the available user types.
    std::cout << "1. Staff Member" << std::endl;
    std::cout << "2. Student" << std::endl;
    std::cout << "3. Visitor / Guest" << std::endl;
    std::cout << "4. Contract Cleaner" << std::endl;
    std::cout << "5. Manager" << std::endl;
    std::cout << "6. Security" << std::endl;
    std::cout << "7. Emergency Responder" << std::endl;
}

// Displays the list of users or a message if no users are present.
void CampusCardUsers::displayUserList() const {
    if (users.empty()) {
        std::cout << "No users are currently saved." << std::endl;
    }
    else {
        // If there are users print their user name and user type.
        std::cout << "User List" << std::endl;
        for (const auto& user : users) {
            std::cout << user.username << " - " << user.userType << std::endl;
        }
    }
}

// Adds a new user to the vector of users.
void CampusCardUsers::addUser(const std::string& username, const std::string& userType) {
    // Create a new user and set their username and user type.
    User newUser;
    newUser.username = username;
    newUser.userType = userType;
    // Add the new user to the vector.
    users.push_back(newUser);
    std::cout << "User " << username << " added successfully." << std::endl;
}

// Updates the user type for an existing user.
void CampusCardUsers::updateUser(const std::string& username, const std::string& newUserType) {
    // Find the user with the specified username in the vector.
    auto it = std::find_if(users.begin(), users.end(), [username](const User& user) {
        return user.username == username;
        });

    if (it != users.end()) {
        // If the user is found update their user type.
        it->userType = newUserType;
        std::cout << "User " << username << " updated successfully." << std::endl;
    }
    else {
        // If the user is not found inform the user.
        std::cout << "User not found. Unable to update." << std::endl;
    }
}

// Removes a user with the specified username from the vector.
void CampusCardUsers::removeUser(const std::string& username) {
    // Find the user with the specified username in the vector.
    auto it = std::find_if(users.begin(), users.end(), [username](const User& user) {
        return user.username == username;
        });

    if (it != users.end()) {
        // If the user is found erase them from the vector.
        users.erase(it);
        std::cout << "User " << username << " removed successfully." << std::endl;
    }
    else {
        // If the user is not found inform the user.
        std::cout << "User not found. Unable to remove." << std::endl;
    }
}

// Provides a menu for interacting with Campus Card Users.
void CampusCardUsers::campusCardUsersMenu() {
    char usersMenuChoice;

    do {
        // Display the menu options for Campus Card Users.
        std::cout << "1. Display User Types" << std::endl;
        std::cout << "2. Display User List" << std::endl;
        std::cout << "3. Add User" << std::endl;
        std::cout << "4. Update User" << std::endl;
        std::cout << "5. Remove User" << std::endl;
        std::cout << "0. Go Back to Main Menu" << std::endl;

        // User input
        std::cout << "Enter your choice:\n ";
        std::cin >> usersMenuChoice;

        // Handle user choice for Campus Card Users
        switch (usersMenuChoice) {
        case '1':
            displayUserTypes();
            break;
        case '2':
            displayUserList();
            break;
        case '3':
        {
            std::string username, userType;
            // Takes input for new user name and user type and adds a new user.
            std::cout << "Enter the new username: ";
            std::cin >> username;
            std::cout << "Enter the user type: ";
            std::cin >> userType;
            addUser(username, userType);
        }
        break;
        case '4':
        {
            std::string username, newUserType;
            // Takes input for username and new user type and updates the user.
            std::cout << "Enter the username to update: ";
            std::cin >> username;
            std::cout << "Enter the new user type: ";
            std::cin >> newUserType;
            updateUser(username, newUserType);
        }
        break;
        case '5':
        {
            std::string username;
            // Takes input for username and removes the user.
            std::cout << "Enter the username to remove: ";
            std::cin >> username;
            removeUser(username);
        }
        break;
        case '0':
            std::cout << "Going back to the Main Menu." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (usersMenuChoice != '0');
}
