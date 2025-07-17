#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>

#include "accessory.h"

Accessory::Accessory(std::string name, std::string description, double price)
{
    this->name= name;
    this->description= description;
    this->price= price;
}

Accessory::~Accessory(){}

Accessory::Accessory(const Accessory& other)
{
    name = other.name;
    description = other.description;
    price = other.price;
}

std::string Accessory::getDetails()
{   std::stringstream output;
    output<<"\nAccessory name: "<<name<<'\n';
    output<<"Description: "<<description<<'\n';
    output<<"Price: "<<price;
    return output.str();
}

double Accessory::getPrice()
{
    return price;
}