#include <bits/stdc++.h>
using namespace std;

// pushes max to the end by adjacent sorting

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter number: ";
        cin >> arr[i];
    }

    int m = n;
    while (m > 1)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
        m--;
    }

    cout << "Sorted array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
