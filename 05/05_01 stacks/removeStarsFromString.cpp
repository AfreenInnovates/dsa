class Solution {
public:
    string removeStars(string s) {
        // stack approach
        stack<char> st;

        for (char c : s) {
            if (c != '*') st.push(c);
            else st.pop();
        }
        s = "";
        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }

        reverse(s.begin(), s.end());
        // return s;

        // two pointers:
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            if (s[r] == '*') {
                s[l] = s[r];
                l++;
            } else l--;
        }

        return s.substr(0, l);
    }
};