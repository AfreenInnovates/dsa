#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/find-pivot-index/description/

/*
   Given an array of integers, return the "pivot index".
   The pivot index is the index where the sum of all numbers to the left
   is equal to the sum of all numbers to the right.
*/

// Brute Force Approach
// Time Complexity: O(n^2) because for every index we compute left and right sums using nested loops
// Space Complexity: O(1)
int pivotIndex_bruteForce(vector<int> &nums)
{

    int left_sum = 0;
    int right_sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        left_sum = 0, right_sum = 0;

        for (int j = 0; j < i; j++)
        {
            left_sum += nums[j];
        }

        for (int k = nums.size() - 1; k > i; k--)
        {
            right_sum += nums[k];
        }

        if (left_sum == right_sum)
        {
            return i;
        }
    }

    return -1;
}

// Optimized Prefix Sum Approach
// Time Complexity: O(n) because we make one pass to calculate total sum and one pass to check pivot
// Space Complexity: O(1)
int pivotIndex_approach2(vector<int> &nums)
{
    int total_sum = 0;
    for (int &num : nums)
    {
        total_sum += num;
    }

    int right_sum = 0, left_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // at i, we can calc right_sum = total_sum - left_sum - nums[i]
        // and then compare
        right_sum = total_sum - left_sum - nums[i];

        if (left_sum == right_sum)
        {
            return i;
        }

        // calculate the sum after the check : this makes sure,
        // that you're calculating the before elements, excluding nums[i]
        left_sum += nums[i];
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    cout << "Array: ";
    for (int n : nums)
        cout << n << " ";
    cout << endl;

    cout << "Pivot Index (Brute Force): " << pivotIndex_bruteForce(nums) << endl;

    cout << "Pivot Index (Approach 2): " << pivotIndex_approach2(nums) << endl;

    return 0;
}
