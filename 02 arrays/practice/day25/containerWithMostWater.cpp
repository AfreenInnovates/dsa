#include <bits/stdc++.h>
using namespace std;

/*
 * Brute Force
 * Time Complexity:  O(n^2)  — check every pair (i, j)
 * Space Complexity: O(1)
 */
int maxAreaBrute(const vector<int> &arr)
{
    int n = (int)arr.size();
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int currentArea = min(arr[i], arr[j]) * (j - i);
            best = max(best, currentArea);
        }
    }
    return best;
}

/*
 * Two-Pointer (Optimal)
 * Time Complexity:  O(n)    — single pass from both ends
 * Space Complexity: O(1)
 */
int maxArea(vector<int> &height)
{
    int left = 0, right = (int)height.size() - 1;
    int maxAreaVal = 0;

    while (left < right)
    {
        int currentArea = min(height[left], height[right]) * (right - left);
        maxAreaVal = max(maxAreaVal, currentArea);

        if (height[left] < height[right])
            ++left;
        else
            --right;
    }
    return maxAreaVal;
}

int main()
{
    int n;
    cout << "Enter number of heights: ";
    if (!(cin >> n) || n < 0)
    {
        cout << "Invalid input\n";
        return 0;
    }

    vector<int> h(n);
    cout << "Enter " << n << " heights: ";
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    vector<int> h_copy = h;

    int bruteAns = maxAreaBrute(h_copy);
    int optimalAns = maxArea(h);

    cout << "Brute Force (O(n^2))  : " << bruteAns << '\n';
    cout << "Two-Pointer (O(n))    : " << optimalAns << '\n';

    return 0;
}
