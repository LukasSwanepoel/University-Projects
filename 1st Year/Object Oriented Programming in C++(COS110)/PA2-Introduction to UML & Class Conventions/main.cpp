#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>

#include "accessory.h" 
#include "engine.h"
#include "car.h"

int main() 
{    
    Engine F6("Flat 6", 510, 3.6, 5000);
    std::cout << "\nEngine Price: " << F6.getPrice() << "\n";
    std::cout << "Engine Details:" << F6.getDetails() << "\n";

    Accessory Aero("Weissach", "Carbon Fibre Bits", 200);
    Accessory Breaks("Carbon Ceramic Breaks", "Sylica Carbide Discs, no overheating", 600);
    std::cout << "Accessory Price: " << Aero.getPrice() << "\n";
    std::cout << "Accessory Details:" << Aero.getDetails() << "\n";
    
    Car Porsche911GT3("Track Supercar", 2);
    
    Porsche911GT3.addAccessory(&Aero);
    Porsche911GT3.addAccessory(&Breaks);
    Porsche911GT3.setEngine(&F6); 
    std::cout << "\nCar Price: " << Porsche911GT3.getPrice() << "\n";
    std::cout << "Car Name: " << Porsche911GT3.getName() << "\n";
    std::cout << "Number of Accessories: " << Porsche911GT3.getNumAccessories() << "\n";
    std::cout << "Accessories: " << *Porsche911GT3.getAccessoriesArr() << "\n";
    std::cout << "Engine: " << Porsche911GT3.getEngine() << "\n";           
    std::cout << Porsche911GT3.getDetails() << "\n";

    Car Porsche911GT3RS = Porsche911GT3;
    Porsche911GT3RS.addAccessory(new Accessory("DRS", "Active Aero", 300));
    std::cout << "\nOther car:\n" << Porsche911GT3RS.getDetails() << "\n";
    
    return 0;
}