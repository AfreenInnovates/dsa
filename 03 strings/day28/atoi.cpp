#include <bits/stdc++.h>
using namespace std;

// Time:  O(n) — single pass
// Space: O(1)
int myAtoi(string s)
{
    int i = 0, n = s.size(), sign = 1;
    long long result = 0;

    while (i < n && s[i] == ' ')
        i++;

    if (i < n && (s[i] == '-' || s[i] == '+'))
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    while (i < n && s[i] >= '0' && s[i] <= '9')
    {
        int digit = s[i] - '0';

        if (sign == 1)
        {
            if (result > (INT_MAX - digit) / 10LL)
                return INT_MAX;
        }
        else
        {
            if (result > ((long long)INT_MAX + 1 - digit) / 10LL)
                return INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}

int main()
{
    vector<string> tests = {
        "42",
        "   -42",
        "4193 with words",
        "words and 987",
        "-91283472332",
        "2147483647",
        "-2147483648",
        "2147483648",
        "-2147483649",
        "   +00123"};

    for (auto &t : tests)
    {
        cout << "Input: \"" << t << "\" -> Output: " << myAtoi(t) << endl;
    }

    return 0;
}
