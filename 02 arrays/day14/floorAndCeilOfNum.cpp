#include <bits/stdc++.h>
using namespace std;

// Find Ceil: smallest element >= x
int findCeil(vector<int> arr, int x, int n)
{
    int low = 0, high = n - 1;
    int mid = 0;
    int ans = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] >= x)
        {
            ans = arr[mid]; // possible ceil
            high = mid - 1; // look for smaller valid ceil
        }
        else
        {
            low = mid + 1; // move right
        }
    }

    return ans;
}

// Find Floor: largest element <= x
int findFloor(vector<int> arr, int x, int n)
{
    int low = 0, high = n - 1;
    int mid = 0;
    int ans = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] <= x)
        {
            ans = arr[mid]; // possible floor
            low = mid + 1;  // look for larger valid floor
        }
        else
        {
            high = mid - 1; // move left
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 4, 6, 8, 10};
    int n = arr.size();

    int x1 = 5;
    int x2 = 0;
    int x3 = 10;

    cout << "For x = " << x1 << " → Floor = " << findFloor(arr, x1, n)
         << ", Ceil = " << findCeil(arr, x1, n) << "\n";

    cout << "For x = " << x2 << " → Floor = " << findFloor(arr, x2, n)
         << ", Ceil = " << findCeil(arr, x2, n) << "\n";

    cout << "For x = " << x3 << " → Floor = " << findFloor(arr, x3, n)
         << ", Ceil = " << findCeil(arr, x3, n) << "\n";

    return 0;
}
