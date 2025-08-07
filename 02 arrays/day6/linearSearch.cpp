#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // return index where element found
        }
    }
    return -1; // element not found
}

int main()
{
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> target;

    int result = linearSearch(arr, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
