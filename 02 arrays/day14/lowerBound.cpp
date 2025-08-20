#include <bits/stdc++.h>
using namespace std;

// time: O(log N) base 2
int lowerBound(vector<int> nums, int x)
{
    int low = 0, high = nums.size() - 1, mid = 0;
    int ans = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (nums[mid] >= x)
        {
            ans = mid;      // potential answer
            high = mid - 1; // look for earlier occurrence
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
    vector<int> nums = {1, 2, 4, 4, 5, 7, 9};

    int x1 = 4;
    int x2 = 6;
    int x3 = 10;

    cout << "Lower bound of " << x1 << " is at index " << lowerBound(nums, x1) << "\n";
    cout << "Lower bound of " << x2 << " is at index " << lowerBound(nums, x2) << "\n";
    cout << "Lower bound of " << x3 << " is at index " << lowerBound(nums, x3) << "\n";

    return 0;
}
