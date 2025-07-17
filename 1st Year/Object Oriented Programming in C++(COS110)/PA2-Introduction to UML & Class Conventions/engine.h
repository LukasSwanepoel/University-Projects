#ifndef ENGINE_H
#define ENGINE_H

#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>

class Engine
{
private:
    std::string name;
    int horsepower, displacement;
    double price;

public:
    Engine(std::string name, int horsepower, int displacement, double price);
    Engine(const Engine& other);
    ~Engine();

    std::string getDetails();
    double getPrice();
};
#endif