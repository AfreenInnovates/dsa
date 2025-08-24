#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    int low = 1, high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid])
        {
            return mid;
        }
        if (nums[mid] > nums[mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};

    cout << "Peak index in nums1: " << findPeakElement(nums1) << "\n";
    cout << "Peak index in nums2: " << findPeakElement(nums2) << "\n";

    return 0;
}
