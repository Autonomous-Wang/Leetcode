#include <iostream>
using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void heapify(int arr[], int n, int i) // n is the number element in the array
                                        // i is the number of parent node selected
{
    int largest = i;  // Initialize largest as root and root should be the smallest
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap max
void Buildheap(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n)
{
    // Build heap (rearrange array) and begin from the last parent node
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    // and heapify reducing length of heap
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        printArray(arr, i);
    }
}

// maxheap insert, n is the size after appending new element
void heapInsert(int arr[], int n, int val)
{
    int parent_index;
    int i = n - 1;
    arr[i] = val;
    if (n % 2 == 0)
        parent_index = n / 2 - 1;
    else
        parent_index = n / 2;
    while(parent_index >= 0 && i >= 0 && arr[parent_index] < arr[i])
    {
        swap(arr[parent_index], arr[i]);
        i = parent_index;
        if (i % 2 == 0)
            parent_index = i / 2 - 1;
        else
            parent_index = i / 2;
    }
}

// l, m, k is the index of the corresponding node in the array
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r-l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
 
 void quickSort(int arr[], int left, int right) 
 {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    /* partition */
    while (i <= j) 
    {
        while (arr[i] < pivot) // we can not use the equation sign
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) 
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
 
// Driver program
int main()
{
    int arr[] = {8, 11, 8, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original array is \n";
    printArray(arr, n);
    //cout << "Maxheap array is \n";
    //Buildheap(arr, n);
    //printArray(arr, n);
    //int ar[n + 1];
    //ar[n] = 0;
    //for (int i = 0; i < n; i++)
      //  ar[i] = arr[i];
    //printArray(ar, n + 1);
    //heapInsert(ar, n + 1, 30);
    quickSort(arr, 0, 5);
    //mergeSort(arr, 0, 5);
    cout << "Inserted array is \n";
    printArray(arr, n);
}









