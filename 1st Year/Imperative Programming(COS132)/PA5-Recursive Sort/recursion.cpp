#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int arrnum[4];
int arr_1 = 0;
int arr_2 = 0;
int temp;

void recursiveSort(int*, int, int);

int main() 
{
	cout << "Enter 4 integer values: ";
	cin >> arrnum[0] >> arrnum[1] >> arrnum[2] >> arrnum[3];

	recursiveSort(arrnum, arr_1, arr_2);

	return 0;
}

void recursiveSort(int* arrnum, int arr_1, int arr_2)
{
	cout << "itr1:" << arr_1 << " itr2:" << arr_2 << " array:";
	cout << arrnum[0] << "," << arrnum[1] << "," << arrnum[2] << "," << arrnum[3] << endl;

	if (arrnum[arr_1] > arrnum[arr_2])
	{
		temp = arrnum[arr_1];
		arrnum[arr_1] = arrnum[arr_2];
		arrnum[arr_2] = temp;
	}

	arr_2++;
	if (arr_2 == 4)
	{
		arr_1++;
		arr_2 = 0;
	}

	if (arr_1 < 4)
	{
		if (arr_2 < 4)
		{
			recursiveSort(arrnum, arr_1, arr_2);
		}
	}
}