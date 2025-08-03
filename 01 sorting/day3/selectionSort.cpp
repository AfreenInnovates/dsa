#include <bits/stdc++.h>
using namespace std;

// selects the minimum value and swaps at every i'th iteration

void selectionSort(int arr[], int n)
{
    for (int i = 0; i <= (n - 2); i++)
    {
        int minIdx = i;
        for (int j = i; j <= (n - 1); j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter number: ";
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// time complexity:
// if n = 5
// outer loop runs from 0, 1, 2, 3 = 4 times, so runs for n - 1 times = O(n) = outer loop time complexity
// inner loops runs from 0, 1, 2, 3, 4 = 5 times.
// when i = 0, j runs from 0 to n (5 times); i = 1, j runs from 0 to n-1 times; i = 2, j from 0 to n-2, and so on.
// so for inner loop: n + (n-1) + (n-2) + (n-3) + ... 2 + 1 = n(n-1)/2 = O(n(n-1)/2) = O(n^2)
// so total time complexity = O(n) + O(n^2) = O(n^2)