#include "dog.h"
#include "citizen.h"

void Dog::setAge(int age)
{
    Age = age;
}

void Dog::setCitizen(Citizen* Citizen)
{
    Owner = Citizen;
}

void Dog::setName(const string &name)
{
    Name = *(&name);
}

const string& Dog::getName() const
{
    return Name;
}

int Dog::getAge() const 
{
    return Age;
}

Citizen* Dog::getCitizen() const{
    return Owner;
}