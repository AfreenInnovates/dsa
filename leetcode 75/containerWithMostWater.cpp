class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, n = height.size(), right = n-1;
        int maxA = INT_MIN;

        while (left<right) {
            int width = right - left;
            int heightWater = min(height[left], height[right]);
            int area = width * heightWater;

            maxA = max(maxA, area);

            if (height[left] > height[right]) right--;
            else left++;
        }
        return maxA;
    }
};