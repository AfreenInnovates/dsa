#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach:

Time Complexity: O(N^3)
   - For each interval, we check all others (O(N^2))
   - and merging/erasing from vector can cost O(N) each time.
Space Complexity: O(1) (in-place merging, ignoring output vector).
*/
vector<vector<int>> mergeBruteForce(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n == 0)
        return {};

    bool merged = true;
    while (merged)
    {
        merged = false;
        for (int i = 0; i < (int)intervals.size(); i++)
        {
            for (int j = i + 1; j < (int)intervals.size(); j++)
            {
                // Check overlap
                if (!(intervals[i][1] < intervals[j][0] || intervals[j][1] < intervals[i][0]))
                {
                    intervals[i][0] = min(intervals[i][0], intervals[j][0]);
                    intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                    intervals.erase(intervals.begin() + j);
                    merged = true;
                    break;
                }
            }
            if (merged)
                break;
        }
    }
    return intervals;
}

/*
Optimized Sort + Merge Approach:

Time Complexity: O(N log N) due to sorting + O(N) for merging
Space Complexity: O(N) for storing result.
*/
vector<vector<int>> mergeOptimized(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end()); // time : O(N log N)
    int n = intervals.size();
    vector<vector<int>> merged_ans;

    // time : O(N)
    for (int i = 0; i < n; i++)
    {
        if (merged_ans.empty() || merged_ans.back()[1] < intervals[i][0])
        {
            merged_ans.push_back(intervals[i]);
        }
        else
        {
            merged_ans.back()[1] = max(merged_ans.back()[1], intervals[i][1]);
        }
    }
    return merged_ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> bruteInput = intervals; // copy
    vector<vector<int>> bruteResult = mergeBruteForce(bruteInput);

    cout << "Brute Force Result:\n";
    for (auto &interval : bruteResult)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << "\n";

    vector<vector<int>> optInput = intervals; // copy
    vector<vector<int>> optResult = mergeOptimized(optInput);

    cout << "Optimized Result:\n";
    for (auto &interval : optResult)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << "\n";

    return 0;
}
