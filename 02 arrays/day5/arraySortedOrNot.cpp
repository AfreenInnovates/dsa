#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> arr, int n)
{
    for (int i = 1; i <= (n - 1); i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
            return false;
    }

    return true;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (isSorted(arr, n))
        cout << "The array is sorted." << endl;
    else
        cout << "The array is not sorted." << endl;

    return 0;
}