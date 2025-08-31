#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Brute Force Approach
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
int findMaxLengthBrute(vector<int> &nums)
{
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int zeroCount = 0, oneCount = 0;

        for (int j = i; j < n; j++)
        {
            if (nums[j] == 0)
                zeroCount++;
            else
                oneCount++;

            if (zeroCount == oneCount)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}

/*
Optimized Hashmap Approach
Time Complexity: O(n)
Space Complexity: O(n)
  - Worst case: store up to n different prefix sums in hashmap.
*/
int findMaxLengthOptimized(vector<int> &nums)
{
    unordered_map<int, int> mpp; // sum -> earliest index
    int sum = 0, maxLen = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += (nums[i] == 0 ? -1 : 1);

        if (sum == 0)
        {
            maxLen = max(maxLen, i + 1);
        }

        if (mpp.find(sum) != mpp.end())
        {
            maxLen = max(maxLen, i - mpp[sum]);
        }
        else
        {
            mpp[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> nums1 = {0, 1};
    vector<int> nums2 = {0, 1, 0};
    vector<int> nums3 = {0, 1, 1, 1, 1, 1, 0, 0, 0};

    cout << "Brute Force Results:\n";
    cout << "Example 1: " << findMaxLengthBrute(nums1) << endl;
    cout << "Example 2: " << findMaxLengthBrute(nums2) << endl;
    cout << "Example 3: " << findMaxLengthBrute(nums3) << endl;

    cout << "\nOptimized Hashmap Results:\n";
    cout << "Example 1: " << findMaxLengthOptimized(nums1) << endl;
    cout << "Example 2: " << findMaxLengthOptimized(nums2) << endl;
    cout << "Example 3: " << findMaxLengthOptimized(nums3) << endl;

    return 0;
}
