#include "Reservation.h"

Reservation::Reservation(const Room &reservedRoom, const Customer &reservingCustomer)
        : room(reservedRoom), customer(reservingCustomer) {}
