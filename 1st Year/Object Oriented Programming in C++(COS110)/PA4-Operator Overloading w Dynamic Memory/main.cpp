#include <fstream>
#include <iostream>

#include "warehouse.h"

using namespace std;

int main() {
    fstream file("input.txt");
    warehouse* w = new warehouse(5);
    file >> *w;
    file >> *w;
    cout << *w;
    file.close();
    delete w;
    return 0;
}
