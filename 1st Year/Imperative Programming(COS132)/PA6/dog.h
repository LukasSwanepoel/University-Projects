#ifndef TEST_DOG_H
#define TEST_DOG_H

#include <string>
#include "citizen.h"
using namespace std;

class Dog {

    private:
        string Name;
        int Age;
		Citizen* Owner;
	public:
		Dog(){};
		~Dog(){};
		const string &getName() const;
		void setName(const string &name);
		int getAge() const;
		void setAge(int age);
		void setCitizen(Citizen* Citizen);
		Citizen* getCitizen() const;
};

#endif //TEST_DOG_H
