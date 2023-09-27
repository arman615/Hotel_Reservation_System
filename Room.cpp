#include "Room.h"

Room::Room(int number, const std::string &roomType)
        : roomNumber(number), type(roomType), status("Available") {}

int Room::getRoomNumber() const {
    return roomNumber;
}

std::string Room::getType() const {
    return type;
}

std::string Room::getStatus() const {
    return status;
}

void Room::setStatus(const std::string &newStatus) {
    status = newStatus;
}
