#include <iostream>
using namespace std;

int main()
{
	int n = 10, temp; int arr[10] = { 91,84,71,62,53,49,30,27,11,5 };
	cout << "```BUBBLE SORTING ALGORITHM:```\n";
	cout << "\nNow un-sorted Elemets of array: ";
	for (size_t sf = 0; sf < n; sf++)
	{
		cout << arr[sf] << "\t";
	} 
  cout << endl;
	
  //sorting block
  for (size_t i = 0; i < n; i++)
	{	//it will transverse loop n times. where n = no of elements
		for (size_t j = 0; j < n - i - 1; j++)
		{	//this loop will compare adjacent elements 
			if (arr[j] > arr[j + 1])	
			{	//if value at j+1 is higher than j than swaping will happen.
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;	//tenp is use to hold temparaory value.
			}
		}
	}
  
	cout << "\nNow displaying sorted array: ";
	for (size_t sf = 0; sf < n; sf++)
	{
		cout << arr[sf] << "\t";
	} cout << endl;
}
