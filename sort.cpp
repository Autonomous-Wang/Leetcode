// calculate the document distance from MIT algorithm online course
#include <iostream>
#include <vector>
using namespace std;

void printvec(vector<int> arr)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

// counting sort based on the given range
vector<int> countsort(vector<int> arr, int range)
{
    int n = arr.size();
    vector<int> res (n, 0);
    vector<int> count (range, 0);

    for (int i : arr)
        ++count[i];

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < n; i++)
    {
        res[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    return res;
}

// O(n^2) for vector implementation pass by refernce
// so that we can change the entry of each element
void insort(vector<int> &arr)
{
	int n = arr.size();
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		while (i >= 0 && j >= 0 && arr[j] > arr[i])
		{
			// swap the entries of vector also need to reduce the index
			swap(arr[i], arr[j]);
			i--;
			j--;
		}
	}
}

// merge two sorted array in O(n)
// change the entry of arr, don't create new vector
void merge(vector<int> &arr, int l, int m, int r)
{
	int n = arr.size();
    int ln = m - l + 1;
    int rn = n - ln;
    vector<int> L(ln);
    vector<int> R(rn);

    for (int i = 0; i < ln; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < rn; j++)
        R[j] = arr[ln + l + j];

    int i(0), j(0);
    int k = l;

    while (i < ln && j < rn)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    while (i < ln)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < rn)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// O(nlogn)
void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
	}
}

void maxheapify(vector<int> &arr, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxheapify(arr, largest, n);
    }
    return;
}

void buildmaxheap(vector<int> &arr, int n)
{
    for (int i = n / 2; i >= 0; i--)
        maxheapify(arr, i, n);
}

void heapsort(vector<int> &arr)
{
    int n = arr.size();
    buildmaxheap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        maxheapify(arr, 0, i);
    }
}

void quicksort(vector<int> &arr, int l, int r)
{
    int mid = l + (r - l) / 2;
    int pivo = arr[mid];
    int i = l;
    int j = r;

    while (i <= j)
    {
        while (arr[i] < pivo) {i++;}
        while (arr[j] > pivo) {j--;}
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    if (l < j)
        quicksort(arr, l, j);
    if (i < r)
        quicksort(arr, i, r);
}

int main()
{
	vector<int> a = {5, 12, 4, 6, 10, 3};
	int n = a.size();
	quicksort(a, 0, n - 1);
    printvec(a);
}







