#include <bits/stdc++.h>
using namespace std;

bool searchInSortedArrayII(vector<int> nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1, mid = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            return true;
        }

        if (nums[mid] == nums[low] && nums[high] == nums[mid])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }

        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[mid] <= target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = -1;

    cout << "Array: ";
    for (int x : nums)
        cout << x << " ";
    cout << "\nTarget: " << target << "\n";

    bool found = searchInSortedArrayII(nums, target);

    if (found)
        cout << "Target " << target << " exists in the array.\n";
    else
        cout << "Target " << target << " does not exist in the array.\n";

    return 0;
}
