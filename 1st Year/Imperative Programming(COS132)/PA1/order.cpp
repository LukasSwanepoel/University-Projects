#include <iostream>
using namespace std;

int main()
{
	int itm, amnt, pfood, pdrink, amntdrink;
	string drink, food;
	bool fdrink;

	cout 
	<< "What would you like to order?" << endl 
	<< "MENU" << endl 
	<< "1) Burger" << endl 
	<< "2) Pizza" << endl 
	<< "3) Quit" <<endl 
	<< "Please enter your choice: ";

	cin >> itm;

	if (itm==1)
	{
		cout	
		<< "1) Chicken R35" << endl
		<< "2) Beef R40" << endl
		<< "3) vegan R45" << endl
		<< "Please enter your choice (flavour): ";

		cin >> itm;
		
		if(itm== 1)
		{
			food = "Chicken Burger R35";
			pfood = 35;
		}
		else if(itm== 2)
		{
			food= "Beef Burger R40";
			pfood  = 40;
		}
		else if(itm == 3)
		{
			food= "Vegan Burger R45";
			pfood  = 45;
		}
		
		cout << "Please enter quantity: ";
		cin >> amnt; 
 	}
	else if (itm==2)
	{
		cout	
		<< "1) Small R25" << endl
		<< "2) Medium R50" << endl
		<< "3) Large R75" << endl
		<< "Please enter your choice (size): ";

		cin >> itm;

		if(itm == 1)
		{
			food = "Small Pizza R25";
			pfood  = 25;
		}
		else if(itm == 2)
		{
			food = "Medium Pizza R50";
			pfood  = 50;
		}
		else if(itm == 3)
		{
			food = "Large Pizza R75";
			pfood  = 75;
		}

		cout << "Please enter quantity: ";
		cin >> amnt; 	
	}
	else if (itm==3)
	{
		return 0;
	}	

	cout << "Would you like to order a drink? (yes/no): ";
	cin >> drink;

	if (drink=="yes")
	{
		fdrink = true;
		cout 
		<< "1) Cola R10" << endl
		<< "2) Juice R13" << endl
		<< "3) Coffee R16" << endl
		<< "Please enter your choice: ";

		cin >> itm;

		if (itm == 1)
		{
			drink = "Cola R10";
			pdrink = 10;
		} 
		else if (itm == 2)
		{
			drink= "Juice R13";
			pdrink = 13;
		}
		else if(itm == 3)
		{
			drink = "Coffee R16";
			pdrink = 16;
		}

		cout << "Please enter quantity: ";	
		cin >> amntdrink;
	}
	else if(drink== "no")
	{
		fdrink = false;
	}

	cout 
	<< "You ordered the following items:" << endl
	<< "- "<< amnt << " x " << food << endl;
    if (fdrink == true)
	{
		cout << "- "<< amntdrink << " x " << drink<< endl
		<<"Total = R" << (pfood * amnt) + (pdrink * amntdrink) << endl;
	}
	else if(fdrink == false)
	{
		cout <<"Total = R" << (pfood* amnt) << endl;
	}

	cout << "Your order will be delivered soon, have a lovely day!" << endl;
	
	return 0;
}