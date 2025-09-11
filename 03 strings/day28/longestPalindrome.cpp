#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force with explicit palindrome check
Time:  O(n^3) — choose (i, j) → O(n^2), and each isPalin check is up to O(n)
Space: O(1) — constant extra space
Intuition:
  Enumerate all substrings s[i..j], check if it’s a palindrome by expanding inward.
  Track the best (start, maxLen). Conceptually simplest but slow.
*/

// approach 1 : O(N^3)
bool isPalin(int low, int high, const string &s)
{
    while (low < high)
    {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}

string longestPalindrome_bruteforce(const string &s)
{
    int maxLen = 1;
    int start = 0;
    int n = (int)s.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalin(i, j, s) && (j - i + 1) > maxLen)
            {
                start = i;
                maxLen = j - i + 1;
            }
        }
    }
    return s.substr(start, maxLen);
}

/*
Approach 2: Expand Around Center
Time:  O(n^2) — each index can be a center; expanding from each center is linear in total
Space: O(1) — constant extra space
Intuition:
  Every palindrome is defined by a center. For each i, expand for:
    - odd length (low = i,   high = i)
    - even length (low = i,  high = i+1)
  Expand while characters match, update (start, maxLen).
*/

// ==============================
string longestPalindrome_expand(const string &s)
{
    int n = (int)s.size();
    if (n == 0)
        return "";

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            int low = i;
            int high = i + j;

            // so we will expand till left side till the letter at 0th index
            // on the L.H.S. and high will start from the next letter of ith
            // position, till < n we'll run as long as the letters on the
            // lhs and rhs are same
            while (low >= 0 && high < n && s[low] == s[high])
            {
                int currLen = high - low + 1;
                if (currLen > maxLen)
                {
                    start = low;
                    maxLen = currLen;
                }
                low--;  // wherever low ends, where the palindrome starts,
                        // will be final value
                high++; // wherever ends
            }
        }
    }
    return s.substr(start, maxLen);
}

int main()
{
    vector<string> pal_tests = {
        "babad",            // "bab" or "aba"
        "cbbd",             // "bb"
        "a",                // "a"
        "ac",               // "a" or "c"
        "aaaabaaa",         // "aaabaaa"
        "forgeeksskeegfor", // "geeksskeeg"
        "abcd",             // "a" (any single char)
        "abba",             // "abba"
        "abcba"             // "abcba"
    };

    cout << "=== Longest Palindromic Substring ===\n";
    for (auto &s : pal_tests)
    {
        string ans1 = longestPalindrome_bruteforce(s);
        string ans2 = longestPalindrome_expand(s);
        cout << "s = \"" << s << "\"\n";
        cout << "  brute (O(n^3)):  \"" << ans1 << "\"\n";
        cout << "  expand (O(n^2)): \"" << ans2 << "\"\n";
    }
    cout << "\n";

    return 0;
}
