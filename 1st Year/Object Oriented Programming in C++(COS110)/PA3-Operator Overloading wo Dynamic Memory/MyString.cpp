#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "MyString.h"

MyString::MyString()
{
    mString = "";
}

MyString::MyString(std::string instring)
{
    mString= cleanString(instring);
}

std::string MyString::cleanString(std::string dirtystring)
{
    std::string newstring="";
    for (int i=0; i<dirtystring.length(); i++)
    {
        if ((int(dirtystring[i])>47)&&(int(dirtystring[i])<58))
        {
            newstring+= dirtystring[i];
        }
        else if ((int(dirtystring[i])>64)&&(int(dirtystring[i])<91))
        {
            newstring+= dirtystring[i];
        }
        else if ((int(dirtystring[i])>96)&&(int(dirtystring[i])<123))
        {
            newstring+= dirtystring[i];
        }
    }

    return newstring;
}

    /*--------------------COMPRESSION ARLGORITHM------------
    
    std::string squStr="";

    for (int i=0; i<mString.length();i++)
        {
            if ((int(mString[i])>64)&&(int(mString[i])<91))
            {
                squStr+= tolower(mString[i]);
            }
            else
            {
                squStr += mString[i];
            }
        }*/

MyString::~MyString(){}

void MyString::print()
{
    std::cout<<mString<<'\n';
}

std::string MyString::operator+(std::string rhs)
{
    return mString+cleanString(rhs);
}

std::string MyString::operator+(const MyString& rhs)
{
    return mString+rhs.mString;
}

MyString& MyString::operator+=(const MyString& rhs)
{
    this->mString += rhs.mString;
    return *this;
}

bool MyString::operator<(const MyString& rhs)
{   //compress
    std::string squStr="";

    for (int i=0; i<mString.length();i++)
        {
            if ((int(mString[i])>64)&&(int(mString[i])<91))
            {
                squStr+= tolower(mString[i]);
            }
            else
            {
                squStr += mString[i];
            }
        }
    //cont as norm
    bool decided=false;
    int pos=0;
    if (squStr.length()==rhs.mString.length())
    {
        while (!decided)
        {
            if (int(squStr[pos])<int(rhs.mString[pos]))
            {return true;}
            else if (int(squStr[pos])>int(rhs.mString[pos]))
            {return false;}
            else
            {
                pos++;
                if (pos==squStr.length())
                {return false;}
            }
        }
    }
    else if (squStr.length()>rhs.mString.length())
    {
        while (!decided)
        {
            if (int(squStr[pos])<int(rhs.mString[pos]))
            {return true;}
            else if (int(squStr[pos])>int(rhs.mString[pos]))
            {return false;}
            else
            {
                pos++;
                if (pos==rhs.mString.length())
                {return false;}
            }
        }
    }
    else if (squStr.length()<rhs.mString.length())
    {
        while (!decided)
        {
            if (int(squStr[pos])<int(rhs.mString[pos]))
            {return true;}
            else if (int(squStr[pos])>int(rhs.mString[pos]))
            {return false;}
            else
            {
                pos++;
                if (pos==squStr.length())
                {return true;}
            }
        }
    }

    return false;
}

bool MyString::operator>(const MyString& rhs)
{
    //compress
    std::string squStr="";

    for (int i=0; i<mString.length();i++)
        {
            if ((int(mString[i])>64)&&(int(mString[i])<91))
            {
                squStr+= tolower(mString[i]);
            }
            else
            {
                squStr += mString[i];
            }
        }
    //contasnorm
   bool decided=false;
    int pos=0;

    if (squStr.length()==rhs.mString.length())
    {
        while (!decided)
        {
            if (int(squStr[pos])<int(rhs.mString[pos]))
            {return false;}
            else if (int(squStr[pos])>int(rhs.mString[pos]))
            {return true;}
            else
            {
                pos++;
                if (pos==squStr.length())
                {return false;}
            }
        }
    }
    else if (squStr.length()>rhs.mString.length())
    {
        while (!decided)
        {
            if (int(squStr[pos])<int(rhs.mString[pos]))
            {return false;}
            else if (int(squStr[pos])>int(rhs.mString[pos]))
            {return true;}
            else
            {
                pos++;
                if (pos==rhs.mString.length())
                {return true;}
            }
        }
    }
    else if (squStr.length()<rhs.mString.length())
    {
        while (!decided)
        {
            if (int(squStr[pos])<int(rhs.mString[pos]))
            {return false;}
            else if (int(squStr[pos])>int(rhs.mString[pos]))
            {return true;}
            else
            {
                pos++;
                if (pos==squStr.length())
                {return false;}
            }
        }
    }

    return false;
}

bool MyString::operator==(const MyString& rhs)
{
    //compress mString
    std::string squStr1="", squStr2="";

    for (int i=0; i<mString.length();i++)
        {
            if ((int(mString[i])>64)&&(int(mString[i])<91))
            {
                squStr1+= tolower(mString[i]);
            }
            else
            {
                squStr1 += mString[i];
            }
        }
    //compress other string
    for (int i=0; i<rhs.mString.length();i++)
        {
            if ((int(rhs.mString[i])>64)&&(int(rhs.mString[i])<91))
            {
                squStr2+= tolower(rhs.mString[i]);
            }
            else
            {
                squStr2 += rhs.mString[i];
            }
        }
    //compare strings now
    if (squStr1==squStr2)
    {return true;}
    else
    {return false;}
}

bool MyString::operator!=(const MyString& rhs)
{
    if (*this==rhs)
    {return false;}
    else
    {return true;}
}
MyString& MyString::operator=(std::string input)
{
    mString= cleanString(input);
    return *this;
}

MyString& MyString::operator=(std::fstream& file)
{
    char c;

    if (file.fail())
    {
        return *this;
    }
    else if (file.peek()!=file.eof())
    {
        while (file.get(c))
        {
            mString+=c;
        }
        mString= cleanString(mString);
        return *this;
    }
    else {mString=""; return *this;}
}

MyString& MyString::operator=(const MyString& rhs)
{
    mString = rhs.mString;
    return *this;
}

void MyString::clear()
{
    mString = "";
}

bool MyString::operator!()
{
    if (mString.length()==0)
    {
        return true;
    }
    else {return false;}
}