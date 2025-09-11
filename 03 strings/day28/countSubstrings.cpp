#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute force (generate & count)
Time:  O(n^3) — two loops over (i,j) and O(n) substring construction
Space: O(1) extra (each temporary substring is discarded immediately; transient O(n))
Intuition:
  Enumerate every start/end pair (i,j), actually build the substring (expensive),
  and count it. Conceptually simplest, but slow.
*/
long long countSubstrings_bruteforce_build(const string &s)
{
    long long cnt = 0;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            string t = s.substr(i, j - i + 1);
            (void)t;
            ++cnt;
        }
    }
    return cnt;
}

/*
Approach 2: Double loops, no building
Time:  O(n^2) — enumerate all (i,j) pairs
Space: O(1)
Intuition:
  We only need the COUNT of substrings, not the substrings themselves.
  Still visit each pair (i,j) but avoid constructing strings.
*/
long long countSubstrings_pairs(const string &s)
{
    long long cnt = 0;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            ++cnt;
    return cnt;
}

/*
Approach 3: Sum-by-start (or end)
Time:  O(n)
Space: O(1)
Intuition:
  For a fixed start i, valid ends are i..n-1 → (n - i) substrings.
  Sum over i: (n) + (n-1) + ... + 1.
*/
long long countSubstrings_sumByStart(const string &s)
{
    long long cnt = 0;
    long long n = (long long)s.size();
    for (long long i = 0; i < n; ++i)
        cnt += (n - i);
    return cnt;
}

/*
Approach 4: Closed-form formula
Time:  O(1)
Space: O(1)
Intuition:
  Number of pairs (i,j) with 0 ≤ i ≤ j < n equals n*(n+1)/2.
*/
long long countSubstrings_formula(long long n)
{
    return n * (n + 1) / 2;
}

int main()
{

    string s = "abcde";
    cout << "=== Count substrings for: \"" << s << "\" (n=" << s.size() << ") ===\n";
    cout << "Brute (build):           " << countSubstrings_bruteforce_build(s) << '\n';
    cout << "Double loops (no build): " << countSubstrings_pairs(s) << '\n';
    cout << "Sum by start (O(n)):     " << countSubstrings_sumByStart(s) << '\n';
    cout << "Formula (O(1)):          " << countSubstrings_formula((long long)s.size()) << '\n';

    return 0;
}
