#include <bits/stdc++.h>
using namespace std;

/*
  Maximum Subarray Product — Brute Force (O(n^3))

  Time  : O(n^3)  — choose i, choose j, and multiply elements i..j each time
  Space : O(1)    — constant extra space
*/
long long maxSubarrayProductN3(vector<int> nums)
{
    int n = nums.size();
    long long best = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int prod = 1;
            for (int k = i; k < j; k++)
            {
                prod = prod * nums[k];
            }
            best = max(best, (long long)prod);
        }
    }
    return best;
}

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

        pre = pre * nums[i];
        suf = suf * nums[n - i - 1];

        maxi = max(maxi, max(pre, suf));
    }
    return maxi;
}
