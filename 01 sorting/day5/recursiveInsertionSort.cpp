#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int i, int n)
{
    // best case
    if (i == n)
        return;

    // while loop won't run when array is sorted
    int j = i;
    while ((j > 0) && (arr[j - 1] > arr[j]))
    {
        swap(arr[j], arr[j - 1]);
        j--;
    }

    insertionSort(arr, i + 1, n);
}

int main()
{

    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, 0, n);
    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}