#ifndef CAR_H
#define CAR_H

#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>

#include "engine.h"
#include "accessory.h"

class Car
{
private:
    std::string name;
    int numAccessories;
    Engine* engine;
    Accessory** accessories;

public:
    Car(std::string name, int numAccessories);
    Car(const Car& other);
    ~Car();

    Car& operator=(const Car& other);

    double getPrice();
    std::string getName();
    int getNumAccessories();
    Accessory** getAccessoriesArr();
    Engine* getEngine();
    bool addAccessory(Accessory* accessory);
    void setEngine(Engine* engine);
    std::string getDetails();

};

#endif