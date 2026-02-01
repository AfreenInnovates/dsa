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

// using stacks
// we find the next greater elements for elements in nums2 and keep in a stack and map the numbers to its greater elements
// then loop through nums1 and then find its next greater in the map
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nge;

        for (int i=nums2.size()-1; i>=0; i--) {
            int ele = nums2[i];
            while (!st.empty() && st.top() <= ele) st.pop(); // keep popping until we find the element greater than 'ele'

            nge[ele]=st.empty() ? -1 : st.top(); // if stack is empty (we find no next greater element) then -1, else the top element will be the next greater for the current 'ele'

            st.push(ele);
        }

        vector<int>ans;
        for (int num: nums1) {
            ans.push_back(nge[num]);
        }
        return ans;
    }
};