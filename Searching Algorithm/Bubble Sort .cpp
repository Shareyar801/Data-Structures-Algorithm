#include <iostream> 
#include <string> 
#include <algorithm>
using namespace std;

void main()
{
	int arr[20], key_val, count = 0; bool check = 1;
	int str = 0, end = 19, mid = (str + end) / 2;

	cout << "Enter 20 elements of array: \n";
	for (size_t sf = 0; sf < 20; sf++)
	{
		cout << "INDEX " << sf << ": ";
		cin >> arr[sf];
	}

	cout << "\nEnter a key value to find from array: ";
	cin >> key_val;
	while (str <= end)
	{
		mid = (str + end) / 2;
		if (key_val == arr[mid])
		{

			cout << "Value " << key_val << " found.";
			break;

		}
		else if (key_val <= arr[mid])
		{
			end = mid - 1;
		}
		else if (key_val >= arr[mid])
		{
			str = mid + 1;
		}
		count++;
	}

	cout << "\nNumber of comparsions taken: " << count << endl << endl;
}
