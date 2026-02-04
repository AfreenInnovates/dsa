class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        // brute force
        for (int i=0;i <heights.size();i++) {
            int l=i,r=i;
            int h=heights[i];

            // move on the left, till we find something that's less than the current height, and move till the first element only (l>=0)
            while (l>=0 && heights[l]>= heights[i]) l--;

            //now move on the right till block that's bigger or equal to current block height
            while (r<heights.size() && heights[r]>=heights[i]) r++;

            int width=(r-l-1);
            int area = width*heights[i];

            // cout<<"area, width, height for " << heights[i] << " is " << area << " " << width << " " << heights[i] << " and l and r respc " << l << " " << r <<endl;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};