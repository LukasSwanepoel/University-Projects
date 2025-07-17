#ifndef ACCESSORY_H
#define ACCESSORY_H

#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>

class Accessory
{
private:
    std::string name, description;
    double price;

public:
    Accessory(std::string name, std::string description, double price);
    ~Accessory();
    Accessory(const Accessory& other);

    std::string getDetails();
    double getPrice();

};

#endif