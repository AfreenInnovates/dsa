class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i_s=0;

        for (int jt = 0; jt<t.size(); jt++) {
            if (t[jt] == s[i_s]) i_s++;
        }

        return i_s == s.size();
    }
};