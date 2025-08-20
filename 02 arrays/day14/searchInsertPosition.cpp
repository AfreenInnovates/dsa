#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int high = n - 1, low = 0;
    int mid = 0, ans = n;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (nums[mid] >= target)
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
    vector<int> nums = {1, 3, 5, 6};

    int t1 = 5; // already present
    int t2 = 2; // should be inserted at index 1
    int t3 = 7; // should be inserted at the end
    int t4 = 0; // should be inserted at index 0

    cout << "searchInsert(" << t1 << ") = " << searchInsert(nums, t1) << "\n";
    cout << "searchInsert(" << t2 << ") = " << searchInsert(nums, t2) << "\n";
    cout << "searchInsert(" << t3 << ") = " << searchInsert(nums, t3) << "\n";
    cout << "searchInsert(" << t4 << ") = " << searchInsert(nums, t4) << "\n";

    return 0;
}
