#include <iostream> 
#include <string> 
using namespace std;
void main()
{
start:
	int ch, arr[20], key_val; bool check = 1;
	int str = 0, end = 19, mid = (str + end) / 2, count = 0;
	cout << "===Menu===\n01.For linear search\n02.For binary search\n03.exit\nEnter:";
	cin >> ch;

	switch (ch)
	{
	case 01:
	{
		cout << "Enter 20 elements of array: \n";
		for (size_t sf = 0; sf < 20; sf++)
		{
			cout << "INDEX " << sf << ": ";
			cin >> arr[sf];
		}
		cout << "Enter a key value to find from array: ";
		cin >> key_val;
		for (size_t sf = 0; sf < 20; sf++)
		{
			if (key_val == arr[sf])
			{
				cout << "Key value found! at index " << sf << endl;
				check = 0;
				break;
			}
			check = 1;
		}
		if (check == 1)
		{
			cout << "key value not found.\n";
		}
	} break;
	case 02:
	{
		cout << "Enter 20 elements of array: \n";
		for (size_t sf = 0; sf < 20; sf++)
		{
			cout << "INDEX " << sf << ": ";
			cin >> arr[sf];
		}
		cout << "Enter a key value to find from array: ";
		cin >> key_val;
		while (str <= end)
		{
			mid = (str + end) / 2;
			if (key_val == arr[mid])
			{
				cout << "\nValue " << key_val << " found.";
				check = 0;
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
		if (check == 0)
		{
			cout << "\nNumber of comparsions taken: " << count << endl << endl;
		}
		else if (check == 1)
		{
			cout << "key value not found.\n";
		}
	} break;
	case 03:
	{
		exit(0);
	} break;
	}
	cout << endl;
	goto start;
}
