#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity:  O(log n)
Space Complexity: O(1)
*/
int binarysearch_approach(vector<int> nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (nums[mid] <= target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements (rotated sorted array): ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter target: ";
    cin >> target;

    int index = binarysearch_approach(nums, target);

    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}
