// Logs.h
#ifndef LOGS_H
#define LOGS_H

#include <fstream>
#include <vector>
#include "CampusCardUsers.h"
#include "RoomConfiguration.h"

class Logs {
public:
    // Static function to save data to a file
    static void saveData(const CampusCardUsers& campusCardUsers, const RoomConfiguration& roomConfig, const std::string& filename);
};

#endif