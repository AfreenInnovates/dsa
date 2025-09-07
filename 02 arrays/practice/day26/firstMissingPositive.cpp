// https://leetcode.com/problems/first-missing-positive/

#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach
--------------------
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
int firstMissingPositiveBrute(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i <= n + 1; i++)
    {
        bool found = false;
        for (int num : nums)
        {
            if (num == i)
            {
                found = true;
                break;
            }
        }
        if (!found)
            return i;
    }
    return n + 1;
}

/*
Hashing / Extra Space Approach
------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/
int firstMissingPositiveHash(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> present(n + 1, false);

    for (int num : nums)
    {
        if (num > 0 && num <= n)
        {
            present[num] = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!present[i])
        {
            return i;
        }
    }
    return n + 1;
}

int main()
{
    vector<int> nums = {3, 4, -1, 1};

    // Brute force
    vector<int> temp1 = nums;
    cout << "Brute Force Result: " << firstMissingPositiveBrute(temp1) << endl;

    // Hashing / Extra space
    vector<int> temp2 = nums;
    cout << "Hashing Result: " << firstMissingPositiveHash(temp2) << endl;
    return 0;
}
