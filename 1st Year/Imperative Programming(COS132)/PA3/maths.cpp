#include <iostream>
using namespace std;

double linearEquation(int);
double quadraticEquation(int);
double exponentialEquation(int,double,double);

int main() 
{
	cout<< "--- MATHEMATICS CALCULATOR ---"<<endl;

	unsigned int choice;
	int x;
	double result;

	while (choice!=4)
	{
		cout
		<<"What would you like to do?"<<endl
		<<"1) Calculate F(x)"<<endl
		<<"2) Calculate G(x)"<<endl
		<<"3) Calculate S(x)"<<endl
		<<"4) Exit"<<endl
		<<"Enter your choice: ";

		cin	>>choice;
		if (choice==4) return 0;
		cout<<"Enter the value of x: ";
		cin	>>x;

		if (choice==1) result =linearEquation(x);
		if (choice==2) result =quadraticEquation(x);
		if (choice==3)
		{
			double F,G;
			F=linearEquation(x);
			G=quadraticEquation(x);
			result =exponentialEquation(x,F,G);
		}
		cout<<"Results = "<<result<<endl;
	}
	return 0;
}

//function declaration section
	
double linearEquation(int x){return 3*x-1;}
double quadraticEquation(int x){return ((linearEquation(x)*linearEquation(x))+3*linearEquation(x)+4);}
double exponentialEquation(int x,double F,double G)
{
	double product;
	product =1;

	int counter;

	if (x>0){
		counter = 1;
		while (counter<=x)
		{
			product= product * F; 
			counter=counter+1;
		} 
	}

	if (x<0)
	{
		counter = 1;
		while (counter<=(-1*x))
		{	
			product= product * F; 
			counter=counter+1;
		} 

		product=1/product;

	}
	
	if (x==0){product=1;}

	return G*product;
}