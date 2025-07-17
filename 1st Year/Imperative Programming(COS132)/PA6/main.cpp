#include <iostream>
#include "dog.h"

void swapNames(Dog& first, Dog& second)
{
    Dog WoofenTmp;
    WoofenTmp.setName(first.getName());
    first.setName(second.getName());
    second.setName(WoofenTmp.getName());
}

int main() {
    Dog objWoofen[10];
    Citizen objCitizen[10];
    Dog* dog1;
    Dog* dog2;
    int AgeDog, MenuOption, index = -1;
    string InputString, Name, TheOtherName, NameOwner, Address, Output;

    while (MenuOption != 3)
    {
        cout << "Enter 1 to add a dog, 2 to swap names or 3 to stop: ";
        cin >> MenuOption;

        if (MenuOption == 1)
        {
            index++;
            cout << "Please enter the name of the dog: ";
            cin >> Name;
            objWoofen[index].setName(Name);
            cout << "Please enter the age: ";
            cin >> AgeDog;
            objWoofen[index].setAge(AgeDog);
            cout << "Does the dog have an owner: ";
            cin >> InputString;

            if (InputString == "Yes")
            {
                cout << "Please enter the owners name: ";
                cin >> NameOwner;
                objCitizen[index].setName(NameOwner);
                cout << "Please enter the address: ";
                cin >> Address;
                objCitizen[index].setAddress(Address);
            }
            else if (InputString == "No")
            {
                NameOwner = "hoping for adoption";
                objCitizen[index].setName(NameOwner);
            }

            objWoofen[index].setCitizen(&objCitizen[index]);
            cout << "The list of dogs are as follows: ";

            for (int i = 0; i <= index; i++)
            {
                if (i != 0)
                {
                    cout << ", ";
                }
                cout << objWoofen[i].getName() << "(Owner: ";
                Citizen objTmp = *objWoofen[i].getCitizen();
                cout << objTmp.getName() << ")";
            }
            cout << endl;
        }
        else if (MenuOption == 2)
        {
            bool flag1, flag2;
            cout << "Enter name of first dog: ";
            cin >> Name;
            cout << "Enter name of second dog: ";
            cin >> TheOtherName;

            for (int i = 0; i <= index; i++)
            {
                if (Name == objWoofen[i].getName())
                {
                    dog1 = &objWoofen[i];
                    flag1 = true;
                }
                if (TheOtherName == objWoofen[i].getName())
                {
                    dog2 = &objWoofen[i];
                    flag2 = true;
                }
            }

            if ((flag1 == true) && (flag2 == true))
            {
                swapNames(*dog1, *dog2);
                cout << "The list of dogs are as follows: ";
                for (int i = 0; i <= index; i++)
                {
                    if (i != 0)
                    {
                        cout << ", ";
                    }
                    cout << objWoofen[i].getName() << "(Owner: ";
                    Citizen objTmp = *objWoofen[i].getCitizen();
                    cout << objTmp.getName() << ")";
                }
                cout << endl;
            }
            else
            {
                cout << "No dog found" << endl;
            }
        }
        else if (MenuOption == 3)
        {
            return 0;
        }
    }
    cout << endl << "The list of dogs are as follows: " << Output << endl;
    main();
    return 0;
}
