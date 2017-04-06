// peak find in the array
#include <iostream>
using namespace std;

// find peak in the two dimension array 

int findPeakUtil(int arr[], int low, int high, int n)
{
	int mid = low + (high - low) / 2;

	// need to  
	if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == n - 1 || 
		arr[mid] > arr[mid + 1]))
		return arr[mid];

	else if (mid > 0 && arr[mid - 1] > arr[mid])
		return findPeakUtil(arr, low, mid - 1, n);

	else 
		return findPeakUtil(arr, mid + 1, high, n); 
}

int findPeak(int arr[], int n)
{
	return findPeakUtil(arr, 0, n - 1, n);
}

int main()
{
	int arr[] = {1, 3, 10, 24};
	int n = sizeof(arr)/sizeof(int);
	cout << findPeak(arr, n) << endl;
}

