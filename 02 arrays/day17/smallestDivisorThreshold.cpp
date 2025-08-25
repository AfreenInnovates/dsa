#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMinAndMax(vector<int> &nums)
{
    int n = nums.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        mini = min(mini, nums[i]);
        maxi = max(maxi, nums[i]);
    }

    return {mini, maxi};
}

// approach 1
int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    pair<int, int> p = findMinAndMax(nums);
    int maxi = p.second;

    for (int i = 1; i <= maxi; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += (nums[j] + i - 1) / i; // integer trick
        }
        if (sum <= threshold)
            return i;
    }
    return -1;
}

// helper for approach 2
static inline bool findIfPossible(const vector<int> &nums, int d, int threshold)
{
    long long sum = 0;
    for (int x : nums)
    {
        sum += (x + d - 1) / d;
        if (sum > threshold)
            return false;
    }
    return sum <= threshold;
}

// approach 2 : Binary Search
int smallestDivisor2(vector<int> &nums, int threshold)
{
    pair<int, int> p = findMinAndMax(nums);
    int maxi = p.second;

    int low = 1, high = maxi, mid = 0, ans = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (findIfPossible(nums, mid, threshold))
        {
            ans = mid;
            high = mid - 1; // try smaller divisor
        }
        else
        {
            low = mid + 1; // need bigger divisor
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {44, 22, 33, 11, 1};
    int threshold = 5;

    cout << "=== Approach 1 ===" << endl;
    int result1 = smallestDivisor(nums, threshold);
    cout << "Smallest divisor: " << result1 << endl;

    cout << "\n=== Approach 2 (Binary Search) ===" << endl;
    int result2 = smallestDivisor2(nums, threshold);
    cout << "Smallest divisor: " << result2 << endl;

    return 0;
}
