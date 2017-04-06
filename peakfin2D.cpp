// peak find in 2D array
#include <iostream>
using namespace std;

#define N 4

int findPeakcol(int arr[N][N], int low, int high, int n, int col)
{
	int mid = low + (high - low) / 2;

	if ((mid == 0 || arr[mid][col] > arr[mid - 1][col]) && (mid == n - 1 || 
		arr[mid][col] > arr[mid + 1][col]))
		return mid;

	else if (mid > 0 && arr[mid - 1][col] > arr[mid][col])
		return findPeakcol(arr, low, mid - 1, n, col);

	else 
		return findPeakcol(arr, mid + 1, high, n, col); 
}

int findPeak(int arr[N][N], int low_col, int high_col, int n)
{
	int mid_col = low_col + (high_col - low_col) / 2;
	// row index corresponding to peak col
	int index = findPeakcol(arr, 0, n - 1, n, mid_col);

	if ((mid_col == 0 || arr[index][mid_col] > arr[index][mid_col - 1]) && (mid_col == n - 1 || 
		arr[index][mid_col] > arr[index][mid_col + 1]))
		return arr[index][mid_col];

	else if (mid_col > 0 && arr[index][mid_col - 1] > arr[index][mid_col])
		return findPeak(arr, low_col, mid_col - 1, n);

	else 
		return findPeak(arr, mid_col + 1, high_col, n);
}

int main()
{
	int arr[N][N] = 
	{
		{1, 3, 10, 24},
		{3, 5, 6, 33},
		{1, 6, 20, 37},
		{3, 7, 19, 29}
	};

	cout << findPeak(arr, 0, 3, N) << endl;
}





