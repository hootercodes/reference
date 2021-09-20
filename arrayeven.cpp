// CPP program to check if all elements
// of an array are even or odd.
#include <algorithm>
#include <iostream>
using namespace std;

void even_or_not(int arr[], int len)
{
	// all_of() returns true if given operation is true
	// for all elements, otherwise returns false.
	all_of(arr, arr + len, [](int i) { return i % 2; }) ?
						cout << "All are even elements" :
						cout << "All are not even elements";
}

int main()
{
	int arr[] = { 2, 4, 6, 12, 14, 17 };
	int len = sizeof(arr) / sizeof(arr[0]);
	even_or_not(arr, len);
	return 0;
}
