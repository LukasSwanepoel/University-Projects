#include "citizen.h"

Citizen::Citizen() 
{
	
}

Citizen::~Citizen() 
{

}

void Citizen::setName(const string &name)
{
    Name = *(&name);
}

const string& Citizen::getName() const
{
    return Name;
}

void Citizen::setAddress(const string &address)
{
    Address = *(&address);
}

const string& Citizen::getAddress() const
{
    return Address;
}
