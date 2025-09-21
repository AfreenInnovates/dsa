#include <iostream>
#include <vector>
using namespace std;

/*
   Given an array, return the index of the largest number
   if it is at least twice as large as every other number.
   Otherwise, return -1.
*/

// https://leetcode.com/problems/largest-number-at-least-twice-of-others/

// approach 1
// Time Complexity: O(n) -> two passes through the array
// Space Complexity: O(1) -> only a few variables used
class Solution1
{
public:
    int dominantIndex(vector<int> &nums)
    {
        // first approach in mind
        // find the largest -> loop through array and check if it is >= nums[i] * 2

        int largest = nums[0], largestIndex = 0, count = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > largest)
            {
                largest = nums[i];
                largestIndex = i;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == largestIndex)
                continue;
            if (largest < nums[i] * 2)
            {
                return -1; // false condition so just return -1
            }
        }

        return largestIndex;
    }
};

// approach 2
// Time Complexity: O(n) -> two passes (one to find largest, one to validate)
// Space Complexity: O(1)
class Solution2
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int largest = nums[0], largestIndex = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > largest)
            {
                largest = nums[i];
                largestIndex = i;
            }
        }

        // check with count
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == largestIndex)
            {
                count++; // include the largest element as auto-pass
                continue;
            }
            if (largest >= 2 * nums[i])
            {
                count++;
            }
        }

        // verify count : it means all the elements whose twiced up value was less than largestNum, so it must be same as nums.size()
        if (count == nums.size())
        {
            return largestIndex;
        }
        return -1;
    }
};

// Time Complexity: O(n) -> single pass to find largest and second largest
// Space Complexity: O(1)
int dominantIndex(vector<int> &nums)
{

    // next approach ->
    // find largest and secondLargest ->
    // if secondLargest*2 <= largest ->
    // largest will be greater than others twiced up value for SURE
    // so one pass optimized solution

    int largest = -1, secondLargest = -1, largestIndex = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > largest)
        {
            secondLargest = largest;
            largest = nums[i];
            largestIndex = i;
        }
        else if (nums[i] > secondLargest)
        {
            secondLargest = nums[i];
        }
    }

    if (largest >= secondLargest * 2)
    {
        return largestIndex;
    }
    return -1;
}

int main()
{
    vector<int> nums = {3, 6, 1, 0};

    cout << "Array: ";
    for (int n : nums)
        cout << n << " ";
    cout << endl;

    Solution1 s1;
    Solution2 s2;

    cout << "Approach 1 Result: " << s1.dominantIndex(nums) << endl;
    cout << "Approach 2 Result: " << s2.dominantIndex(nums) << endl;
    cout << "Optimal Approach Result: " << dominantIndex(nums) << endl;

    return 0;
}
