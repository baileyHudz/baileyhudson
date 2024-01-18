// CampusCardUsers.h
#ifndef CAMPUSCARDUSERS_H
#define CAMPUSCARDUSERS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

class CampusCardUsers {
public:
    // Define a struct to represent a user with user name and user type.
    struct User {
        std::string username;
        std::string userType;
    };

protected:
    // Vector to store the collection of users.
    std::vector<User> users;

public:
    void displayUserTypes() const;

    // Displays the list of users or a message if no users 
    void displayUserList() const;

    // Adds a new user to the vector of users.
    void addUser(const std::string& username, const std::string& userType);

    // Updates the user type for an existing user.
    void updateUser(const std::string& username, const std::string& newUserType);

    // Removes a user with the specified user name from the vector.
    void removeUser(const std::string& username);

    const std::vector<User>& getUsers() const;

    void campusCardUsersMenu();
};

#endif
