#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "MyString.h"

int main()
{   
    MyString zoey("zoey");
    zoey.print();
    MyString abigail("abigail");
    abigail.print();
    MyString clone("clone");
    std::cout<<(zoey<abigail)<<'\n';
    std::cout<<(zoey>abigail)<<'\n';
    //std::cout<<msObj.getMString();
    std::cout<<(zoey==abigail)<<'\n';
    std::cout<<(zoey!=abigail)<<'\n';
    MyString zoeyClone;
    zoeyClone = zoey;
    zoeyClone.print();
    zoeyClone+=clone;
    zoeyClone.print();

    std::fstream infile("sisters.txt");
    MyString sisters;
    sisters =infile;
    sisters.print();
    sisters = zoeyClone;
    sisters.print();
    return 0;
}