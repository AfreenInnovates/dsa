#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute force, recompute frequency for every substring

Time Complexity: O(n^3 + 26 * n^2) ≈ O(n^3)
- For each start i (n choices) and end j (n choices), we loop k from i..j to
  recompute the 26-letter frequency fresh: that inner loop is O(j-i+1) and
  across all (i, j) pairs sums to O(n^3).
- After counting, we scan 26 letters to get max/min among non-zero counts,
  adding only a constant ~26 per substring (dominated by n^3).

Space Complexity: O(26) = O(1)
- Only a small fixed-size array of 26 counters per substring.

Intuition:
- Enumerate every substring and count its character frequencies from scratch.
  Very straightforward but wasteful since adjacent substrings share most work.
*/
long long beautySum_bruteforce_recompute(const string &s)
{
    int n = (int)s.size();
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int freq[26] = {0};
            for (int k = i; k <= j; k++)
            {
                char c = s[k];
                if (c >= 'A' && c <= 'Z')
                    freq[c - 'A']++;
                else if (c >= 'a' && c <= 'z')
                    freq[c - 'a']++;
            }
            int mx = INT_MIN, mn = INT_MAX;
            for (int t = 0; t < 26; t++)
            {
                if (freq[t] > 0)
                {
                    mx = max(mx, freq[t]);
                    mn = min(mn, freq[t]);
                }
            }
            if (mn == INT_MAX)
                mn = 0; // no letters present (only possible on empty, which we don't form)
            ans += (mx - mn);
        }
    }
    return ans;
}

/*
Approach 2: Expand window from each start, maintain freq incrementally; scan 26 each time

Time Complexity: O(26 * number_of_substrings) = O(26 * n^2) ≈ O(n^2)
- Fix start i. As j moves i->n-1, update freq for s[j] in O(1).
- For each (i, j), compute max/min by scanning the 26-length freq array → O(26).
- There are O(n^2) substrings overall, so total is O(26 * n^2).

Space Complexity: O(26) = O(1)
- One 26-length array per start i.

Intuition:
- Avoid re-counting characters for overlapping substrings. For a fixed i,
  we extend j one step at a time and just bump one counter, then evaluate
  beauty by scanning the tiny 26-letter alphabet.
*/
long long beautySum_expand_and_scan26(const string &s)
{
    int n = (int)s.size();
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int freq[26] = {0};
        for (int j = i; j < n; j++)
        {
            char c = s[j];
            if (c >= 'A' && c <= 'Z')
                freq[c - 'A']++;
            else if (c >= 'a' && c <= 'z')
                freq[c - 'a']++;

            int mx = 0, mn = INT_MAX;
            for (int t = 0; t < 26; t++)
            {
                if (freq[t] > 0)
                {
                    mx = max(mx, freq[t]);
                    mn = min(mn, freq[t]);
                }
            }
            if (mn == INT_MAX)
                mn = 0;
            ans += (mx - mn);
        }
    }
    return ans;
}

/*
Time Complexity: O(n^2) with a very small alphabet-dependent constant
- We still enumerate O(n^2) substrings by expanding j for each i.

*/
long long beautySum_countOfCounts(const string &s)
{
    int n = (int)s.size();
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int freq[26] = {0};

        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;

            int mx = 0, mn = INT_MAX;

            for (int f : freq)
            {
                if (f > 0)
                {
                    mx = max(mx, f);
                    mn = min(mn, f);
                }
            }
            ans += (mx - mn);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s))
    {
        return 0;
    }

    for (char &c : s)
        c = (char)tolower((unsigned char)c);

    long long ans1 = beautySum_bruteforce_recompute(s);
    long long ans2 = beautySum_expand_and_scan26(s);
    long long ans3 = beautySum_countOfCounts(s);

    cout << "Approach 1 (Brute force recompute): " << ans1 << "\n";
    cout << "Approach 2 (Expand + scan 26):      " << ans2 << "\n";
    cout << "Approach 3 (Count-of-counts):       " << ans3 << "\n";
    return 0;
}
