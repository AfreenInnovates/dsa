// https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/
class Solution {
public:
    // brute force
    // time complexity :
    // Worst-case time: O(n · max(nums[i]))
    // With constraints substituted: O(100 · 1000) = O(100000) -> acceptable
    // even though values can be large in general, here nums[i] <= 1000

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;

        // max length of nums given to be 100
        // time : O(100) at max
        for (int i = 0; i < nums.size(); i++) {
            bool found = false;

            // find a number x, from 0 to less than nums[i] (number at ith position)
            // such that nums[i] == (x | (x+1))
            
            // max nums[i] given to be 1000
            // time : O(1000) at max
            for (int x = 0; x < nums[i]; x++) {
                if (nums[i] == (x | (x + 1))) {
                    found = true;
                    res.push_back(x);
                    break;
                }
            }

            // if no such x is found, push -1
            if (found == false) res.push_back(-1); // same as if (!found)
        }

        return res;
    }
};
