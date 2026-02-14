class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        int n = nums.size();

        if (n == 1) return 0;  
        // only one element -> already balanced

        int subA = 1;  
        // length of the subarray which contains valid max <= min*k

        sort(nums.begin(), nums.end());  

        int l = 0;  
        // left pointer -> points to current min

        for (int r = 0; r < n; r++) {

            // if max > min*k
            // move front pointer until window becomes valid
            while ((long long)nums[r] > (long long)nums[l] * k) {
                l++;  
                // shrinking window from left
            }

            // now window [l .. r] is valid
            subA = max(subA, r - l + 1);
        }

        return n - subA;  
        // we keep largest valid subarray
        // everything else is removed
    }
};
