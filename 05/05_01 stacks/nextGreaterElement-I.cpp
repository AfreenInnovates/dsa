class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        for (int i = 0; i<nums1.size(); i++) {
            int curr = nums1[i];
            int pos = -1;

            for (int j=0; j<nums2.size();j++) {
                if (nums2[j] == curr) {
                    pos = j;
                    break;
                }
            }

            int nextGreater=-1;
            for (int j =pos+1;j<nums2.size();j++) {
                if (nums2[j] > curr) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            res.push_back(nextGreater);
        }

        return res;
    }
};