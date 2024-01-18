// CampusSimulation.h
#ifndef CAMPUSSIMULATION_H
#define CAMPUSSIMULATION_H

#include <iostream>
#include <vector>

class CampusSimulation {
private:
    // Private member variables to store room and user information
    std::vector<std::string> roomNumbers;
    std::vector<std::string> roomTypes;
    std::vector<std::string> roomStates;
    std::vector<std::string> usernames;
    std::vector<std::string> userTypes;

public:
    // Public member functions for the CampusSimulation class

    // Function to start the simulation
    void runSimulation();

  
    void enterRoomInformation();

  
    void enterUserInformation();

    void changeRoomState();
    void grantDenyAccess();

};

#endif
