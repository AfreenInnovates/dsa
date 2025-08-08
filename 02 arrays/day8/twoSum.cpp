#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach
--------------------
Time Complexity:
    - Outer loop runs n times → O(n)
    - Inner loop runs up to n times → O(n)
    - Total = O(n * n) = O(n²)
Space Complexity:
    - No extra data structure → O(1)
*/
vector<int> twoSumBrute(vector<int> nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

/*
Better Approach: Sorting + Two Pointers
---------------------------------------
Steps:
    1. Store (value, original_index) pairs → O(n) space
    2. Sort by value → O(n log n) time
    3. Use two-pointer technique to find target sum → O(n) time
Time Complexity:
    - Sorting: O(n log n)
    - Two-pointer scan: O(n)
    - Total = O(n log n)
Space Complexity:
    - Store original indices in a separate vector → O(n)
*/
vector<int> twoSumBetter(vector<int> nums, int target)
{
    vector<pair<int, int>> arr; // {value, original_index}
    for (int i = 0; i < nums.size(); i++)
    {
        arr.push_back({nums[i], i});
    }
    sort(arr.begin(), arr.end());

    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int sum = arr[left].first + arr[right].first;
        if (sum == target)
        {
            return {arr[left].second, arr[right].second};
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {-1, -1};
}

/*
Best Approach: Hash Map
-----------------------
Steps:
    1. Traverse array once
    2. For each element, check if (target - element) exists in map
    3. If yes → return indices, else store element in map
Time Complexity:
    - Each lookup and insert in unordered_map → O(1) average
    - Total = O(n)
Space Complexity:
    - Store at most n elements in map → O(n)
*/
vector<int> twoSumBest(vector<int> nums, int target)
{
    unordered_map<int, int> mpp; // value → index
    for (int i = 0; i < nums.size(); i++)
    {
        int need = target - nums[i];
        if (mpp.find(need) != mpp.end())
        {
            return {i, mpp[need]};
        }
        mpp[nums[i]] = i;
    }
    return {-1, -1};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans1 = twoSumBrute(nums, target);
    cout << "Brute Force: [" << ans1[0] << ", " << ans1[1] << "]\n";

    vector<int> ans2 = twoSumBetter(nums, target);
    cout << "Better (Sorting + Two Pointers): [" << ans2[0] << ", " << ans2[1] << "]\n";

    vector<int> ans3 = twoSumBest(nums, target);
    cout << "Best (Hash Map): [" << ans3[0] << ", " << ans3[1] << "]\n";

    return 0;
}

//
//
//
//
// int main()
// {
//     int n, target;
//     cout << "Enter number of elements: ";
//     cin >> n;

//     vector<int> nums(n);
//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> nums[i];
//     }

//     cout << "Enter target sum: ";
//     cin >> target;

//     // Brute Force
//     vector<int> ans1 = twoSumBrute(nums, target);
//     cout << "Brute Force: [" << ans1[0] << ", " << ans1[1] << "]\n";

//     // Better
//     vector<int> ans2 = twoSumBetter(nums, target);
//     cout << "Better (Sorting + Two Pointers): [" << ans2[0] << ", " << ans2[1] << "]\n";

//     // Best
//     vector<int> ans3 = twoSumBest(nums, target);
//     cout << "Best (Hash Map): [" << ans3[0] << ", " << ans3[1] << "]\n";

//     return 0;
// }