#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>

#include "engine.h"

Engine::Engine(std::string name, int horsepower, int displacement, double price)
{
    this->name= name;
    this->horsepower= horsepower;
    this->displacement= displacement;
    this->price= price;
}

Engine::Engine(const Engine& other)
{
    name= other.name;
    horsepower= other.horsepower;
    displacement= other.displacement;
    price= other.price;
}

Engine::~Engine(){}

std::string Engine::getDetails()
{
    std::stringstream output;
    output<<"\nEngine name: "<<name<<'\n';
    output<<"Horsepower: "<<horsepower<<'\n';
    output<<"Displacement: "<<displacement<<'\n';
    output<<"Price: "<<price;
    return output.str();
}

double Engine::getPrice()
{
    return price;
}