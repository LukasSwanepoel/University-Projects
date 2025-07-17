#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "crate.h"
#include "warehouse.h"

warehouse::warehouse()
{
    crates = new crate*[0];
    numCrates = 0;
}

warehouse::warehouse(int numCrates)
{
    this->numCrates= numCrates;
    crates = new crate*[numCrates];

    for (int i=0; i<numCrates; i++)
    {
       crates[i] = new crate();
    }
}

warehouse::warehouse(int numCrates, crate** crates)
{
    this->numCrates = numCrates;
    crates = new crate*[numCrates];

    for (int i=0; i < numCrates; i++)
    {
        this->crates[i] = new crate(*crates[i]);
    }
}

warehouse::warehouse(const warehouse& w)
{
    numCrates= w.numCrates;
    crates = new crate*[numCrates];

    for (int i=0; i<numCrates; i++)
    {
        crates[i] = new crate(*w.crates[i]);
    }
}

warehouse::~warehouse()
{
    for (int i =0; i<numCrates; i++)
    {
        delete crates[i];
    }
    delete[] crates;
    crates=NULL;
    numCrates=0;
}

int warehouse::getNumCrates()
{
    return numCrates;
}

crate** warehouse::getCrates()
{
    return crates;
}

float warehouse::getValue()
{
    float total=0;

    for (int i=0; i<numCrates; i++)
    {
        total += crates[i]->getValue();
    }

    return total;
}

std::ostream& operator<<(std::ostream& os, warehouse& w)
{
    os<<"--------------------------------------------------------------------------------\n";

    for (int i=0; i<w.getNumCrates(); i++)
    {
        os<<*w.crates[i]<<"\n";
    }

    os<<"--------------------------------------------------------------------------------\n";

    std::stringstream ssdummy;
    std::string sdummy;

    os<<"Warehouse "<<"                                    ";

    os<<w.getNumCrates();
    ssdummy<<w.getNumCrates();
    sdummy= ssdummy.str();
    ssdummy.clear();
    for (int i=0; i< 10-sdummy.length(); i++)
    {
        os<<" ";
    }

    os<<"          R ";
    os<<w.getValue();
    ssdummy<<w.getValue();
    sdummy= ssdummy.str();
    ssdummy.clear();
    for (int i=0; 8- sdummy.length();i++)
    {
        os<<" \n";
    }

    os<<"--------------------------------------------------------------------------------\n";
    return os;
}

std::istream& operator>>(std::istream& is, warehouse& w)
{
    int additive;
    is>> additive;

    for (int i=0; i<additive; i++)
    {
        crate newcrate = crate();
        is>>newcrate;
        w += newcrate;
    }

    return is;
}

warehouse& warehouse::operator+=(crate& c)
{
    for (int i=0; i< numCrates;i++)
    {
        if (*crates[i]==c)
        {
            *crates[i]+=c.getAmount();
            return *this;
        }
    }

    for (int i=0; i< numCrates; i++)
    {
        if (crates[i]->getName()== "empty")
        {
            crates[i] = new crate(c);
            return *this;
        }
    }
    
    crate** newcrates = new crate*[numCrates+1];
    for (int i=0; i< numCrates; i++)
    {
        newcrates[i] = new crate(*crates[i]);
    }
    newcrates[numCrates]= new crate(c);
    ++numCrates;
    delete [] crates;
    crates = newcrates;

    return *this;
}

warehouse& warehouse::operator-=(crate& c)
{
    for (int i=0; i<numCrates; i++)
    {
        if (*crates[i]==c)
        {
            crates[i]->setAmount(crates[i]->getAmount()-c.getAmount());
        }
    }
    return *this;
}

warehouse warehouse::operator|(int method)
{
    crate *dummy;
    warehouse* newWH = new warehouse(*this);
    
    if (method==0)
    {
        for (int i=1;i< numCrates; i++)
        {
            for (int j=0; j< numCrates-1; j++)
            {
                if ((newWH->crates[j]>=newWH->crates[j+1])
                ||((newWH->crates[j]->getName()==newWH->crates[j+1]->getName())&&(newWH->crates[j]>newWH->crates[j+1])))
                {
                    dummy= newWH->crates[j];
                    newWH->crates[j] = newWH->crates[j+1];
                    newWH->crates[j+1]=dummy;
                }
            }
        }
    }
    else if (method>0)
    {
        for (int i=1; i< numCrates; i++)
        {
            for (int j=0; j< numCrates-1; j++)
            {
                if ((newWH->crates[j]>newWH->crates[j+1])
                ||((newWH->crates[j]->getValue()==newWH->crates[j+1]->getValue())&&(newWH->crates[j]>=newWH->crates[j+1])))
                {
                    dummy= newWH->crates[j];
                    newWH->crates[j] = newWH->crates[j+1];
                    newWH->crates[j+1]=dummy;
                }
            }
        }
    }
    else if (method<0)
    {
        for (int i=1; i< numCrates; i++)
        {
            for (int j=0; j< numCrates-1; j++)
            {
                if ((newWH->crates[j]<newWH->crates[j+1])
                ||((newWH->crates[j]->getValue()==newWH->crates[j+1]->getValue())&&(newWH->crates[j]<=newWH->crates[j+1])))
                {
                    dummy= newWH->crates[j+1];
                    newWH->crates[j+1] = newWH->crates[j];
                    newWH->crates[j]=dummy;
                }
            }
        }
    }

    return *newWH;
}

warehouse& warehouse::operator|=(int method)
{
    crate *dummy;
    
    if (method==0)
    {
        for (int i=1;i< numCrates; i++)
        {
            for (int j=0; j< numCrates-1; j++)
            {
                if ((crates[j]>=crates[j+1])
                ||((crates[j]->getName()==crates[j+1]->getName())&&(crates[j]>crates[j+1])))
                {
                    dummy= crates[j];
                    crates[j] = crates[j+1];
                    crates[j+1]=dummy;
                }
            }
        }
    }
    else if (method>0)
    {
        for (int i=1; i< numCrates; i++)
        {
            for (int j=0; j< numCrates-1; j++)
            {
                if ((crates[j]>crates[j+1])
                ||((crates[j]->getValue()==crates[j+1]->getValue())&&(crates[j]>=crates[j+1])))
                {
                    dummy= crates[j];
                    crates[j] = crates[j+1];
                    crates[j+1]=dummy;
                }
            }
        }
    }
    else if (method<0)
    {
        for (int i=1; i< numCrates; i++)
        {
            for (int j=0; j< numCrates-1; j++)
            {
                if ((crates[j]<crates[j+1])
                ||((crates[j]->getValue()==crates[j+1]->getValue())&&(crates[j]<=crates[j+1])))
                {
                    dummy= crates[j+1];
                    crates[j+1] = crates[j];
                    crates[j]=dummy;
                }
            }
        }
    }

    return *this; 
}

crate& warehouse::operator[](int idx)
{
    crate* dummy;
    if ((idx<=numCrates-1)&&(idx>=0))
    {
        return *crates[idx];
    }
    else
    {
        
    }
}