#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "crate.h"

crate::crate()
{
    name= "empty";
    amount= 0;
    price= 0;
}

crate::crate(std::string name, int amount, float price)
{
    this->name = name;
    this->amount = amount;
    this->price = price;
}

crate::crate(const crate& other)
{
    name = other.name;
    amount = other.amount;
    price = other.price;
}

crate::crate(std::string s)
{
    crate();
    *this | s;
}

void crate::setName(std::string name)
{
    this->name = name;
}

void crate::setAmount(int amount)
{
    this->amount = amount;
}

void crate::setPrice(float price)
{
    this->price = price;
}

std::string crate::getName()
{
    return name;
}

int crate::getAmount()
{
    return amount;
}

float crate::getPrice()
{
    return price;
}

float crate::getValue()
{
    return amount*price;
}

std::ostream& operator<<(std::ostream& os, crate& c)
{   
    std::stringstream ssdummy;
    std::string sdummy;

        os<<c.getName();
        for (int i=0; i<50-c.getName().length(); i++)
        {
            os<<" ";
        }

        os<<c.getAmount();
        ssdummy<<c.getAmount();
        sdummy=ssdummy.str();
        ssdummy.clear();
        for (int i=0; i<10-sdummy.length(); i++)
        {
            os<<" ";
        }

        os<<"R ";

        os<<c.getPrice();
        ssdummy<<c.getPrice();
        sdummy= ssdummy.str();
        ssdummy.clear();
        for (int i=0; i<8-sdummy.length(); i++)
        {
            os<<" ";
        }

        os<<"R ";
        
        os<<c.getValue();
        ssdummy<<c.getValue();
        sdummy = ssdummy.str();
        ssdummy.clear();
        for (int i=0; i<8-sdummy.length(); i++)
        {
            os<<" ";
        }

    return os;
}

std::istream& operator>>(std::istream& is, crate& c)
{
    std::string dummy;
    getline(is,dummy);
    c|dummy;
    return is;
}

crate& crate::operator|(std::string input)
{
    std::stringstream ssdummy;
    int idummy;
    float fdummy;

    if (input.find('|')!=0)
    {
        this->name= input.substr(0,input.find('|'));
    }
    input.erase(0,input.find('|')+1);

    if (input.find('|')!=0)
    {
        ssdummy<<input.substr(0,input.find('|'));
        ssdummy>>idummy;
        this->amount= idummy;
    }
    input.erase(0,input.find('|')+1);

    if (input.length()!=0)
    {
        ssdummy.clear();
        ssdummy<<input;
        ssdummy>>fdummy;
        this->price= fdummy;
    }

    return *this;    
}

crate& crate::operator++()
{
    ++amount;
    return *this;
}

crate crate::operator++(int)
{
    crate dummy(*this);
    ++amount;
    return dummy;
}

crate& crate::operator+=(int a)
{
    amount+=a;
    return *this;
}

crate& crate::operator-=(int a)
{
    amount-=a;
    if (amount<=0)
    {
        name="empty";
        amount=0;
        price=0;
    }

    return *this;
}

bool crate::operator==(crate& other)
{
    if ((name==other.name)&&(price==other.price))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool crate::operator<=(crate& other)
{
    return (name<=other.name);
}

bool crate::operator>=(crate& other)
{
    return (name>=other.name);
}

bool crate::operator<(crate& other)
{
    return (getValue()<=other.getValue());
}

bool crate::operator>(crate& other)
{
    return (getValue()<=other.getValue());
}