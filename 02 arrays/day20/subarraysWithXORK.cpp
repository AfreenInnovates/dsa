#include <bits/stdc++.h>
using namespace std;

// Brute Force: O(close to N^3), Space: O(1)
int countSubarraysWithXor(vector<int> &arr, int K)
{
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int xr = 0;
            for (int k = i; k <= j; k++)
            {
                xr ^= arr[k];
            }
            if (xr == K)
            {
                count++;
            }
        }
    }
    return count;
}

// Better: O(N^2), Space: O(1)
int better(vector<int> &arr, int K)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int xr = 0;
        for (int j = i; j < n; j++)
        {
            xr ^= arr[j];
            if (xr == K)
                count++;
        }
    }
    return count;
}

// Optimal: O(N), Space: O(N) [hashmap]
int optimal(vector<int> &arr, int K)
{
    int n = arr.size();
    int count = 0, xr = 0;
    map<int, int> mpp;
    mpp[xr]++;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        int x = xr ^ K;
        count += mpp[x];
        mpp[xr]++;
    }

    return count;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int K = 6;

    cout << "Brute Force (O(n^3)) result: "
         << countSubarraysWithXor(arr, K) << endl;

    cout << "Better (O(n^2)) result: "
         << better(arr, K) << endl;

    cout << "Optimal (O(n)) result: "
         << optimal(arr, K) << endl;

    return 0;
}
