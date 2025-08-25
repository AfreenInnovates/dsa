#include <bits/stdc++.h>
using namespace std;

// approach 1
// time :
// space :
int daysNeeded(const vector<int> &weights, long long cap)
{
    int days = 1;
    long long load = 0;
    for (int w : weights)
    {
        if (w > cap)
            return INT_MAX; // impossible with this cap
        if (load + w > cap)
        { // start a new day if the current load and next weight exceeds the capacity
            ++days;
            load = w;
        }
        else
        {
            load += w; // increase the load if, load and next weight is less than capacity
        }
    }
    return days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    if (weights.empty())
        return 0;
    int maxW = *max_element(weights.begin(), weights.end());
    long long sum = accumulate(weights.begin(), weights.end(), 0LL);

    for (long long cap = maxW; cap <= sum; ++cap)
    {
        if (daysNeeded(weights, cap) <= days)
        {
            return (int)cap;
        }
    }
    return (int)sum;
}

//
// approach 2 : binary search
// time :
// space :
int shipWithinDays(vector<int> &weights, int days)
{
    if (weights.empty())
        return 0;
    int maxW = *max_element(weights.begin(), weights.end());
    long long sum = accumulate(weights.begin(), weights.end(), 0LL);

    int low = maxW, high = sum, ans = -1;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (daysNeeded(weights, mid) <= days)
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