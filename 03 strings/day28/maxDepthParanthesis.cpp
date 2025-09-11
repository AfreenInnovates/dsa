#include <bits/stdc++.h>
using namespace std;

/*
maxDepth(s):
- finds the maximum nesting depth of parentheses in string s.
- returns -1 if parentheses are unbalanced.

time complexity:
- O(n), because we scan the string once and do O(1) work per character.

space complexity:
- O(1)

intuition:
- increase depth when we see '('
- decrease depth when we see ')'
- track the maximum depth reached
- if depth goes negative or ends non-zero, parentheses are unbalanced
*/
int maxDepth(const string &s)
{
    int res = 0;
    int curr_count = 0;

    for (char brac : s)
    {
        if (brac == '(')
        {
            curr_count++;
            res = max(res, curr_count);
        }
        else if (brac == ')')
        {
            curr_count--;
            if (curr_count < 0)
            { // more ')' than '(' so far
                return -1;
            }
        }
    }

    if (curr_count != 0)
    { // unmatched '('
        return -1;
    }
    return res;
}

int main()
{
    vector<string> tests = {
        "((a)+b)",             // depth 2
        "(1+(2*3)+((8)/4))+1", // depth 3
        "((())",               // unbalanced
        "())(",                // unbalanced
        "abc"                  // no parentheses
    };

    for (auto &s : tests)
    {
        cout << "Input: " << s
             << " -> Max Depth: " << maxDepth(s) << "\n";
    }
    return 0;
}
