#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    bool didSwap = false;
    if (n == 1)
        return;

    for (int i = 0; i <= (n - 2); i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            didSwap = true;
        }
    }

    if (didSwap == false)
        return;
    bubbleSort(arr, n - 1);
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, n);
    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

// For an array of size n, the recursion depth will be :

// bubbleSort(arr, n)
//     → bubbleSort(arr, n - 1)
//     → bubbleSort(arr, n - 2)
//     → ...
//     → bubbleSort(arr, 1)
// so space complexity = O(n)