#include<iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int pindex = low;

    for (int i = low; i < high; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pindex]);
            pindex++;
        }
    }
    swap(arr[pindex], arr[high]); 
    return pindex;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];  

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}