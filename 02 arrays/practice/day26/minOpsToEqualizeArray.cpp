// https://leetcode.com/problems/minimum-operations-to-equalize-array/description/

#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        bool allAreSame = true;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                allAreSame = false;
                break;
            }
        }

        return allAreSame ? 0 : 1;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 1, 1, 1},
        {1, 2, 1, 1},
        {5},
        {2, 2, 2, 3}};

    for (auto nums : testCases)
    {
        cout << "Input: ";
        for (int x : nums)
            cout << x << " ";
        cout << " -> Min Operations: " << sol.minOperations(nums) << endl;
    }

    return 0;
}
