#include <bits/stdc++.h>
using namespace std;

// time: O(N^2)
// space: O(1)
int brute(vector<int> arr)
{
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }

    return count;
}