// brute 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int waterStored=0;

        for (int i =0; i<n; i++) {
            // for each height, find leftMax and rightMax -> this would be total water filled, but only calculate what's above that building's height
            int leftMax=0,rightMax=0;
            
            // to check till most left
            for (int l=i;l>=0;l--) leftMax=max(leftMax, height[l]);

            // to check till right most
            for (int r=i;r<n;r++) rightMax=max(rightMax, height[r]);

            waterStored += min(leftMax, rightMax) - height[i];
        }

            return waterStored;

    }

};

// two pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,leftMax=0,rightMax=0,right=height.size()-1,waterStored=0;

        while (left<right) {
            if (height[left] < height[right]) {
                leftMax=max(leftMax,height[left]);
                waterStored+= leftMax-height[left];
                left++;
            } else {
                rightMax=max(rightMax,height[right]);
                waterStored+= rightMax-height[right];
                right--;
            }
        }

        return waterStored;
    }
};