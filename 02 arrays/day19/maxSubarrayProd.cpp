#include <bits/stdc++.h>
using namespace std;

/*
  Maximum Subarray Product — Brute Force (O(close to n^3))
  Time  : O(n^3) — choose i, choose j, and multiply elements i..j each time
  Space : O(1)
*/
long long maxSubarrayProductN3(vector<int> nums)
{
    int n = nums.size();
    long long best = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            long long prod = 1;
            for (int k = i; k <= j; k++)
            {
                prod *= nums[k];
            }
            best = max(best, prod);
        }
    }
    return best;
}

/*
  Maximum Subarray Product — Improved Brute Force (O(n^2))
  Time  : O(n^2)
  Space : O(1)
*/
long long maxSubarrayProductN2(vector<int> nums)
{
    int n = nums.size();
    long long best = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        long long prod = 1;
        for (int j = i; j < n; j++)
        {
            prod *= nums[j]; // extend product
            best = max(best, prod);
        }
    }
    return best;
}

// Optimized O(n) approach
int maxProduct(vector<int> &nums)
{
    int pre = 1, suf = 1, maxi = INT_MIN;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;

        pre *= nums[i];
        suf *= nums[n - i - 1];

        maxi = max(maxi, max(pre, suf));
    }
    return maxi;
}

int main()
{
    vector<int> nums = {2, 3, -2, 4};

    cout << "Array: ";
    for (int x : nums)
        cout << x << " ";
    cout << "\n";

    cout << "Brute force (O(n^3)) result : " << maxSubarrayProductN3(nums) << "\n";
    cout << "Improved brute (O(n^2)) result : " << maxSubarrayProductN2(nums) << "\n";
    cout << "Optimized (O(n)) result    : " << maxProduct(nums) << "\n";

    return 0;
}
