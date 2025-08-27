#include <bits/stdc++.h>
using namespace std;

/* =======================================================
   Approach 1: Linear Search
   -------------------------------------------------------
   - Time Complexity : O(N * D)
       N = number of stalls
       D = maximum distance between first and last stall
       (because we try every distance from 1..D and check feasibility)
   - Space Complexity: O(1)
   ======================================================= */
bool canPlaceLinear(const vector<int> &stalls, int dist, int cows)
{
    int placed = 1; // place first cow at first stall
    int lastPos = stalls[0];
    for (int i = 1; i < (int)stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= dist)
        {
            placed++;
            lastPos = stalls[i];
            if (placed >= cows)
                return true;
        }
    }
    return false;
}

int maxMinDistLinear(vector<int> stalls, int cows)
{
    sort(stalls.begin(), stalls.end());
    int limit = stalls.back() - stalls.front(); // max possible distance
    for (int d = 1; d <= limit; d++)
    {
        if (!canPlaceLinear(stalls, d, cows))
        {
            return d - 1; // last feasible distance
        }
    }
    return limit; // all distances up to limit are feasible
}

/* =======================================================
   Approach 2: Binary Search (Optimal)
   -------------------------------------------------------
   - Time Complexity : O(N * log D)
       N = number of stalls
       D = maximum distance between first and last stall
       (log D binary search iterations, each checking O(N))
   - Space Complexity: O(1)
   ======================================================= */
bool canPlaceBinary(const vector<int> &pos, int dist, int balls)
{
    int placed = 1;
    int last = pos[0];
    for (int i = 1; i < (int)pos.size(); i++)
    {
        if (pos[i] - last >= dist)
        {
            placed++;
            last = pos[i];
            if (placed >= balls)
                return true;
        }
    }
    return false;
}

int maxMinDistBinary(vector<int> position, int m)
{
    sort(position.begin(), position.end());
    int s = 1;                                  // minimal non-zero distance
    int e = position.back() - position.front(); // maximal distance
    int ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (canPlaceBinary(position, mid, m))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input format:
    // n m
    // n stall positions (integers)
    //
    // Example:
    // 5 3
    // 1 2 8 4 9
    int n, m;
    if (!(cin >> n >> m))
        return 0;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++)
        cin >> stalls[i];

    int ans_linear = maxMinDistLinear(stalls, m);
    int ans_binary = maxMinDistBinary(stalls, m);

    cout << "Max min distance (Linear): " << ans_linear << "\n";
    cout << "Max min distance (Binary): " << ans_binary << "\n";
    return 0;
}
