#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter array length: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter number: ";
        cin >> arr[i];
    }

    for (int i = 0; i <= (n - 1); i++)
    {
        int j = i;
        while ((j > 0) && (arr[j - 1] > arr[j]))
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// time complexity - O(n^2) for worst/average case
// O(n) for best case, when the array given is sorted