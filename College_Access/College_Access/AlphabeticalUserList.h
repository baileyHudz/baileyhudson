// AlphabeticalUserList.h
#ifndef ALPHABETICAL_USER_LIST_H
#define ALPHABETICAL_USER_LIST_H

#include "CampusCardUsers.h"

class AlphabeticalUserList {
public:
    // Constructor that takes a reference to a Campus Card Users object.
    AlphabeticalUserList(CampusCardUsers& campusCardUsers);

    // Default constructor
    AlphabeticalUserList() = default;

    // Displays the list of users alphabetically.
    void showCurrentUserListAlphabetically() const;


    void alphabeticalUserListMenu();

private:
    CampusCardUsers& campusCardUsers;
};

#endif
