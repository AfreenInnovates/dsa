class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";
        stack<char> st;
        string newNum;
        for (int i =0; i<num.size(); i++) {
            char digit = num[i];

            while (!st.empty() && st.top() > digit && k>0) {
                // pop when the element coming is greater, as we just want small elements in the stack
                // we need to do this as long k still exists (>0)
                st.pop();
                k--;
            }

            st.push(digit);
        }
        // if more digits can be removed
        while (!st.empty() && k>0) {
            st.pop();
            k--;
        }

        // if no numbers left
        if (st.empty()) return "0";

        while (!st.empty()) {
            newNum.push_back(st.top());
            st.pop();
        }

        reverse(newNum.begin(), newNum.end());

        // remove leading zeros
        int i = 0;
        while (i < newNum.size() && newNum[i] == '0') {
            i++;
        } 
        newNum = newNum.substr(i);

        return newNum.empty() ? "0" : newNum;
    }
};