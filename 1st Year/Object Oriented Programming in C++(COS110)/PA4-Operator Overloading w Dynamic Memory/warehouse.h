#ifndef WAREHOUSE_H
#define WATEHOUSE_H
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "crate.h"

class warehouse {
private:
    int numCrates;
    crate** crates;

public:
    warehouse();
    warehouse(int numCrates);
    warehouse(int numCrates, crate** crates);
    warehouse(const warehouse& w);
    ~warehouse();
    int getNumCrates();
    crate** getCrates();
    float getValue();
    friend std::ostream& operator<<(std::ostream& os, warehouse& w);
    friend std::istream& operator>>(std::istream& is, warehouse& w);
    warehouse& operator+=(crate& c);
    warehouse& operator-=(crate& c);
    warehouse operator|(int method);
    warehouse& operator|=(int method);
    crate& operator[](int idx);
    warehouse& operator()();
    warehouse& operator()(crate& c);
};

#endif // WAREHOUSE_H