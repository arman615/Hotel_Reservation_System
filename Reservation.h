#ifndef RESERVATION_H
#define RESERVATION_H

#include "Room.h"
#include "Customer.h"

class Reservation {
public:
    Room room;
    Customer customer;

    Reservation(const Room &reservedRoom, const Customer &reservingCustomer);
};

#endif // RESERVATION_H
