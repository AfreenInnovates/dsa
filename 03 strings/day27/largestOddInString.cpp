#include <bits/stdc++.h>
using namespace std;

/*
Approach 1
-------------------------------------------------------------------------------
We keep your two for-loops with j = i + 1. Since the problem wants a *prefix*,
we only consider i == 0 and track the rightmost odd digit index 'best'.

Time  : O(n^2)  (nested loops over i and j)
Space : O(1)
*/
string largestOddNumber_nested(const string &num)
{
    int n = (int)num.size();
    int best = -1; // rightmost index j (>=0) such that num[0..j] forms an odd number

    if (n > 0 && ((num[0] - '0') % 2) != 0)
        best = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            // only prefixes [0..j] count for this problem
            if (i == 0 && ((num[j] - '0') % 2) != 0)
            {
                if (j > best)
                    best = j;
            }
        }
    }
    return (best == -1) ? "" : num.substr(0, best + 1);
}

/*
Approach 2 (scan right-to-left — standard optimal)
--------------------------------------------------
Scan from the end to find the rightmost odd digit at index i.
Return the prefix num[0..i].

Time  : O(n)   (single pass from right to left)
Space : O(1)   (just indices; output substring is the result)
*/
string largestOddNumber_rtl(const string &num)
{
    for (int i = (int)num.size() - 1; i >= 0; --i)
    {
        if ((num[i] - '0') % 2 != 0)
        {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int main()
{
    vector<string> tests = {
        "", "7", "52", "4206", "35427", "7502", "135", "24680", "1001", "1010"};

    for (const auto &s : tests)
    {
        string a = largestOddNumber_nested(s);
        string b = largestOddNumber_rtl(s);
        cout << "num=\"" << s << "\"  ->  nested: \"" << a << "\"  |  rtl: \"" << b << "\"\n";
        if (a != b)
        {
            cerr << "Mismatch for input \"" << s << "\": nested=\"" << a << "\" rtl=\"" << b << "\"\n";
        }
    }
    return 0;
}
