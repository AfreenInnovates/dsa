class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        // //brute force, three loops
        // for (int i=0; i<nums.size(); i++) {
        //     for (int j=i+1; j<nums.size(); j++) {
        //         if (nums[j] > nums[i]) //find for kth number if jth number is
        //         greater than ith number
        //         {
        //             for (int k=j+1; k<nums.size(); k++) {
        //                 if (nums[i] < nums[k] && nums[k] < nums[j]) return
        //                 true;
        //             }
        //         }
        //     }
        // }

        // return false;

        // approach 2 => ith element is the most min, so find the most min
        // element on the go
        //  int numI =nums[0];
        //  for (int j=1; j<nums.size(); j++) {
        //      numI = min(nums[j], numI);

        //     for (int k=j+1; k<nums.size(); k++) {
        //         if (numI<nums[k] && nums[k]<nums[j]) return true;
        //     }
        // }

        // return false;

        
         stack<int> jStack;
        int kN = INT_MIN;

        for(int i = nums.size()-1; i >= 0; i--) {

            int iN = nums[i];

            if(iN < kN)
                return true;

            while(!jStack.empty() && iN > jStack.top()) {
                kN = jStack.top();
                jStack.pop();
            }

            jStack.push(iN);
        }

        return false;
    }
};