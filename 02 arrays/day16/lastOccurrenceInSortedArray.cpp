#include <bits/stdc++.h>
using namespace std;

// time : O(N)
// space : O(1)
int linearApproach(vector<int> nums, int target)
{
    int n = nums.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}

//
// time : O(log N)
// space : O(1)
int binarySearchApproach(vector<int> nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1, mid = 0;
    int ans = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            ans = mid;
            low = mid + 1; // move right to find last occurrence
        }
        else if (nums[mid] > target)
        {
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

    int ans1 = linearApproach(arr, target);
    int ans2 = binarySearchApproach(arr, target);

    cout << "Last occurrence (Linear Search): Index " << ans1 << endl;
    cout << "Last occurrence (Binary Search): Index " << ans2 << endl;

    return 0;
}
