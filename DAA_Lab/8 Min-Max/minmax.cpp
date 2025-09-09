#include <iostream>
using namespace std;

pair<int, int> find_min_max(int arr[], int start, int end) {
    if (start == end)
        return {arr[start], arr[start]};

    if (end == start + 1) {
        if (arr[start] < arr[end])
            return {arr[start], arr[end]};
        else
            return {arr[end], arr[start]};
    }

    int mid = start + (end - start) / 2;
    pair<int, int> left = find_min_max(arr, start, mid);
    pair<int, int> right = find_min_max(arr, mid + 1, end);

    int overall_min = min(left.first, right.first);
    int overall_max = max(left.second, right.second);

    return {overall_min, overall_max};
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter size of array: ";
    int size;
    cin >> size;

    int array[100]; 

    for (int i = 0; i < size; i++) {
        cout << "Enter array element at index " << i << ": ";
        cin >> array[i];
    }

    cout << "\nOriginal Array: ";
    printArray(array, size);

    pair<int, int> result = find_min_max(array, 0, size - 1);
    cout << "\nMinimum value: " << result.first << endl;
    cout << "Maximum value: " << result.second << endl;

    return 0;
}
