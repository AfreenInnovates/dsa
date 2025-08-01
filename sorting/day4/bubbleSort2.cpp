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

    for (int i = n - 1; i >= 1; i--)
    {
        bool swap = false;
        for (int j = 0; j <= (i - 1); j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swap = true;
            }
        }

        if (swap == false)
        {
            break;
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