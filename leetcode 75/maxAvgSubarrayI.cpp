class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size();
        double maxi = INT_MIN, sum=0;

        while (r<n) {
            sum += nums[r];

            // found required length
            if (r-l+1 == k) {
                // update maxi average upto current calculated avg
                maxi=max(maxi, sum/k);

                // reduce the sum by the leftmost element (we'll slide the window next, so remove first and keep sum of k-1 numbers)
                sum -= nums[l];
                l++; // move right, and new window of size k
            }

            r++;

        }

        return maxi;
    }
};
