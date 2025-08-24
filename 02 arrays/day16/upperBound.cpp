#include <bits/stdc++.h>
using namespace std;

// time : O(N)
// space : O(1)
int upperBound1(vector<int> arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > target)
        {
            return i;
        }
    }
    return n;
}

// time : O(log N)
// space : O(1)
int upperBound2(vector<int> arr, int target)
{
    int n = arr.size();
    int high = n - 1, low = 0, mid = 0;
    int ans = n;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target value: ";
    cin >> target;

    int ans1 = upperBound1(arr, target);
    int ans2 = upperBound2(arr, target);

    cout << "Upper Bound (Linear Search): Index " << ans1 << endl;
    cout << "Upper Bound (Binary Search): Index " << ans2 << endl;

    return 0;
}
