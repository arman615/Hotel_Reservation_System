#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
private:
    int roomNumber;
    std::string type;
    std::string status;

public:
    Room(int number, const std::string &roomType);

    int getRoomNumber() const;

    std::string getType() const;

    std::string getStatus() const;

    void setStatus(const std::string &newStatus);
};

#endif // ROOM_H
