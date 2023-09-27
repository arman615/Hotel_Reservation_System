#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    std::string contact;

public:
    Customer(const std::string &customerName, const std::string &customerContact);

    std::string getName() const;

    std::string getContact() const;
};

#endif // CUSTOMER_H
