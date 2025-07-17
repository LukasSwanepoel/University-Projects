#include <sstream>
#include <string>
#include <iostream>
#include <stdlib.h>

#include "engine.h"
#include "accessory.h"
#include "car.h"

Car::Car(std::string name, int numAccessories)
{
    this->name= name;
    engine= NULL;
    this->numAccessories= numAccessories;

    if (numAccessories<=0)
    {
        numAccessories=0;
        accessories=NULL;
    }
    else
    {
        accessories = new Accessory*[numAccessories];
        for (int i=0; i<numAccessories; i++)
            {
                accessories[i]= NULL;
            }
    }
}

Car::Car(const Car& other)
{
    name = other.name;
    numAccessories = other.numAccessories;

    if (other.engine!=NULL)
    {engine = new Engine(*other.engine);}

    
    if (other.accessories!=NULL)
    {
        accessories = new Accessory*[numAccessories];
        for (int i=0; i<numAccessories; i++)
            {
                if (other.accessories[i]!=NULL)
                {accessories[i]= new Accessory(*other.accessories[i]);}
            }
    }
}

Car::~Car(){}

Car& Car::operator=(const Car& other)
{   
    if (this== &other)
    {return *this;}
    //deallocation
    if (engine!=NULL)
    {
        delete engine;
        engine = NULL;
    }

    if (accessories!=NULL)
    {
        for (int i=0; i<numAccessories;i++)
        {
            if (accessories[i]!=NULL)
            {
                delete accessories[i];
            }
        }
        delete [] accessories;
        accessories = NULL;
    }

    this->name= other.name;

    if (other.engine!=NULL)
    {engine= new Engine(*other.engine);}
    else {engine=NULL;}

    if (other.accessories!=NULL)
    {
        this->numAccessories= other.numAccessories;
        accessories = new Accessory*[numAccessories];
        for (int i=0;i<numAccessories;i++)
        {
            if (other.accessories[i]!=NULL)
            {
                accessories[i] = new Accessory(*other.accessories[i]);
            }
            else
            {accessories[i]=NULL;}
        }
    }

    return *this;
}

double Car::getPrice()
{
    double totP=0;

    for (int i=0; i<numAccessories; i++)
    {
        if (accessories[i]!=NULL)
        {
            totP+= accessories[i]->getPrice();
        }
    }

    if (engine!=NULL)
    {
        totP += engine->getPrice();
    }

    return totP;
}

std::string Car::getName()
{
    return name;
}

int Car::getNumAccessories()
{
    return numAccessories;
}

Accessory** Car::getAccessoriesArr()
{
    if (accessories==NULL)
        {return NULL;}
    else
    {
        return accessories;
    }
}

Engine* Car::getEngine()
{
    if (engine==NULL)
    {
        return NULL;
    }
    else
    {
        return engine;
    }
}

bool Car::addAccessory(Accessory* accessory)
{
    int openspaces=0;

    for (int i=0; i<numAccessories;i++)
    {
        if (accessories[i]==NULL){openspaces++;}
    }

    bool canadd, added=false;
    int i=0;
    if (openspaces>0){canadd=true;}

    if (canadd)
    {
        while (added=false)
        {
            if (accessories[i]==NULL)
            {
                accessories[i]= new Accessory(*accessory);
                added=true;
            }
            i++;
        }
    }
    return canadd;
}

void Car::setEngine(Engine* engine)
{
    if ((engine!=NULL)||(engine!=this->engine))
    {
        delete this->engine;
        this->engine = NULL;
        this->engine = new Engine(*engine);
    }
}

std::string Car::getDetails()
{
    std::string outstring;

    outstring+="Details:\nCar: "+name+"\nPrice: ";
    //convert price to string
    std::string sprice;
    std::stringstream ssprice;
    ssprice<<getPrice();
    sprice = ssprice.str();
    outstring+=sprice;
    
    if (engine!=NULL){outstring+=engine->getDetails();}
    
    if (accessories!=NULL)
    {
        for (int i=0;i<numAccessories;i++)
        {
            if (accessories[i]!=NULL)
            {
                outstring+= accessories[i]->getDetails();
            }
        }
    }
    return outstring;
}