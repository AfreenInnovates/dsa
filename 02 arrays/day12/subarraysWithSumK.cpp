#include <bits/stdc++.h>
using namespace std;

// Brute Force: O(n^2), O(1) space
int subarraySumBrute(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
                count++;
        }
    }
    return count;
}

// Time: O(n), Space: O(n)
int subarraySumOptimal(vector<int> &nums, int k)
{
    int n = nums.size();
    map<int, int> mpp; // prefixSum -> frequency
    mpp[0] = 1;

    int preSum = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        preSum += nums[i];
        int remove = preSum - k;
        count += mpp[remove];
        mpp[preSum]++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 1, 1, -1, 2, -1, 1, 1};
    int k = 2;

    cout << "Array: ";
    for (int x : nums)
        cout << x << " ";
    cout << "\nTarget k = " << k << "\n\n";

    int bruteAns = subarraySumBrute(nums, k);
    cout << "Brute Force Count = " << bruteAns << "\n";

    int optimalAns = subarraySumOptimal(nums, k);
    cout << "Optimal Count = " << optimalAns << "\n";

    return 0;
}
