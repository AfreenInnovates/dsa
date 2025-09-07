// https://leetcode.com/problems/minimum-operations-to-transform-string/description/

#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution
{
public:
    int minOperations(string s)
    {
        int ans = 0;
        for (char ch : s)
        {
            if (ch == 'a')
                continue;
            int steps = ('z' - ch) + 1;
            ans = max(ans, steps);
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<string> testCases = {"abc", "zzz", "a", "azc"};

    for (string s : testCases)
    {
        cout << "Input: " << s
             << " -> Min Operations: " << sol.minOperations(s)
             << endl;
    }

    return 0;
}
