#include "Customer.h"

Customer::Customer(const std::string &customerName, const std::string &customerContact)
        : name(customerName), contact(customerContact) {}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getContact() const {
    return contact;
}
