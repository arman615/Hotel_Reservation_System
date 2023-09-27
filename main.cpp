#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Room.h"
#include "Customer.h"
#include "Reservation.h"

void registerRoom(std::vector<Room> &rooms, int roomNumber, const std::string &roomType) {
    if (roomType != "Single" && roomType != "Double" && roomType != "Suite") {
        std::cout << "Invalid room type!\n";
        return;
    }

    Room newRoom(roomNumber, roomType);
    rooms.push_back(newRoom);

    std::cout << "Room registered successfully!\n";
}

void registerCustomer(std::vector<Customer> &customers, const std::string &customerName,
                      const std::string &customerContact) {
    Customer newCustomer(customerName, customerContact);
    customers.push_back(newCustomer);

    std::cout << "Customer registered successfully!\n";
}

bool isRoomAvailable(const Room &room) {
    return room.getStatus() == "Available";
}

void bookRoom(std::vector<Room> &rooms, std::vector<Customer> &customers, std::vector<Reservation> &reservations,
              const std::string &roomType, int roomNumber, const std::string &customerName,
              const std::string &customerContact) {
    if (roomType != "Single" && roomType != "Double" && roomType != "Suite") {
        std::cout << "Invalid room type!\n";
        return;
    }

    std::vector<Room> availableRooms;
    for (const Room &room: rooms) {
        if (room.getType() == roomType && isRoomAvailable(room)) {
            availableRooms.push_back(room);
        }
    }

    if (availableRooms.empty()) {
        std::cout << "No available rooms of type " << roomType << " found.\n";
        return;
    }
    std::cout << "Available rooms of type " << roomType << ":\n";
    for (const Room &room: availableRooms) {
        std::cout << "Room " << room.getRoomNumber() << std::endl;
    }

    Room *selectedRoomPtr = nullptr;
    for (Room &room: rooms) {
        if (room.getRoomNumber() == roomNumber && isRoomAvailable(room)) {
            selectedRoomPtr = &room;
            break;
        }
    }

    if (selectedRoomPtr == nullptr) {
        std::cout << "Invalid room selection or the room is already booked.\n";
        return;
    }

    Customer newCustomer(customerName, customerContact);
    customers.push_back(newCustomer);

    Reservation newReservation(*selectedRoomPtr, newCustomer);
    reservations.push_back(newReservation);

    selectedRoomPtr->setStatus("Booked");

    std::cout << "Room booked successfully!\n";
}

void generateBill(const Reservation &reservation) {
    std::cout << "-------- Bill --------\n";
    std::cout << "Customer: " << reservation.customer.getName() << std::endl;
    std::cout << "Contact: " << reservation.customer.getContact() << std::endl;
    std::cout << "Room Number: " << reservation.room.getRoomNumber() << std::endl;
    std::cout << "Room Type: " << reservation.room.getType() << std::endl;
    std::cout << "----------------------\n";
}

void saveBillToFile(const Reservation &reservation) {
    std::ofstream outputFile("bill.txt");
    if (outputFile.is_open()) {
        outputFile << "-------- Bill --------\n";
        outputFile << "Customer: " << reservation.customer.getName() << std::endl;
        outputFile << "Contact: " << reservation.customer.getContact() << std::endl;
        outputFile << "Room Number: " << reservation.room.getRoomNumber() << std::endl;
        outputFile << "Room Type: " << reservation.room.getType() << std::endl;
        outputFile << "----------------------\n";
        outputFile.close();
        std::cout << "Bill saved to file.\n";
    } else {
        std::cout << "Unable to save bill to file.\n";
    }
}

int main() {
    std::vector<Room> rooms;
    std::vector<Customer> customers;
    std::vector<Reservation> reservations;

    registerRoom(rooms, 101, "Single");
    registerRoom(rooms, 102, "Double");
    registerRoom(rooms, 201, "Single");
    registerRoom(rooms, 202, "Double");

    registerCustomer(customers, "Poghosyan", "Poghosyan.@mail.ru");
    registerCustomer(customers, "Arman", "Arman@gmail.com");

    bookRoom(rooms, customers, reservations, "Single", 101, "Poghosyan", "Poghosyan.@mail.ru");
    bookRoom(rooms, customers, reservations, "Double", 202, "Arman","Arman@gmail.com" );

    generateBill(reservations[0]);
    generateBill(reservations[1]);

    saveBillToFile(reservations[0]);
    saveBillToFile(reservations[1]);

    return 0;
}
