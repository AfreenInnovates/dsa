#include <bits/stdc++.h>
using namespace std;

// time: O(log N)
// space:
// O(n)(with current function signature)
// O(1)(if nums is passed by reference)

int search(vector<int> nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
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

    return -1; // not found
}

int main()
{
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 7;

    int index = search(nums, target);

    if (index != -1)
        cout << "Target " << target << " found at index " << index << "\n";
    else
        cout << "Target " << target << " not found\n";

    return 0;
}
