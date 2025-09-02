#include <bits/stdc++.h>
using namespace std;

// Approach 1: Find all unique quadruples that sum to target
/*
Time Complexity:
    - Three nested loops: O(n^3)
    - hashset operations: O(1) average
    - set insertion for unique quadruples: O(log m)
    => Total: O(n^3 log m), where m is number of unique quadruples

Space Complexity:
    - hashset inside k-loop: O(n)
    - set to store unique quadruples: O(m)
    => Total: O(n + m)
*/
vector<vector<int>> approach1(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long> hashset;
            for (int k = j + 1; k < n; k++)
            {
                long needed = (long)target - ((long)nums[i] + (long)nums[j] + (long)nums[k]);
                if (hashset.find(needed) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)needed};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }

    vector<vector<int>> result(st.begin(), st.end());
    return result;
}

// Approach 2: Two-pointer method after sorting
/*
Time Complexity:
    - Sorting nums: O(n log n)
    - Two nested loops for i and j: O(n^2)
    - Two-pointer search inside: O(n) for each pair (i,j)
    => Total: O(n^3)

Space Complexity:
    - Storing result: O(m), where m is number of unique quadruples
    - No additional significant space (just pointers)
    => Total: O(m)
*/
vector<vector<int>> approach2(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && nums[j] == nums[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if (sum > target)
                    l--;
                else if (sum < target)
                    k++;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    cout << "Approach 1 results:\n";
    vector<vector<int>> res1 = approach1(nums, target);
    for (auto &quad : res1)
    {
        for (int num : quad)
            cout << num << " ";
        cout << "\n";
    }

    cout << "\nApproach 2 results:\n";
    vector<vector<int>> res2 = approach2(nums, target);
    for (auto &quad : res2)
    {
        for (int num : quad)
            cout << num << " ";
        cout << "\n";
    }

    return 0;
}
