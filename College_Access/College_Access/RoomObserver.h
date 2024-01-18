// RoomObserver.h
#ifndef ROOMOBSERVER_H
#define ROOMOBSERVER_H

#include <string>


class RoomObserver {
public:
    //function to update room state
    virtual void updateRoomState(const std::string& roomNumber, const std::string& newState) = 0;
};

#endif 
