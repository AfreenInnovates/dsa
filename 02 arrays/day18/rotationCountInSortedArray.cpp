#include <bits/stdc++.h>
using namespace std;

// approach 1
// time : O(N)
// space : O(1)
int findKRotation(vector<int> arr)
{
    int n = arr.size();
    int min = arr[0], minIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
}

//
// approach 2
// time : O(log N)
// space : O(1)
int findKRotation_bs(vector<int> arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int mid = 0;
    while (low <= high)
    {

        if (arr[low] <= arr[high])
        {
            return low;
        }

        int mid = (low + high) / 2;

        if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int main()
{
    vector<int> arr = {15, 18, 2, 3, 6, 12};

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    // Using linear approach
    cout << "Rotation count (O(N) approach): " << findKRotation(arr) << "\n";

    // Using binary search approach
    cout << "Rotation count (O(log N) approach): " << findKRotation_bs(arr) << "\n";

    return 0;
}
