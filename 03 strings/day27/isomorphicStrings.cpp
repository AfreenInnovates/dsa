#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
 * Problem
 * -------
 * Check whether two strings are isomorphic.
 * Two strings are isomorphic if characters in one string can be replaced
 * consistently to get the other string, with a one-to-one mapping
 * (no two different characters map to the same character).
 * Return true if they are isomorphic, false otherwise.
 */

//
//
/* ==============================
   Time:  O(n)
   Space: O(1)   fixed 256-sized arrays
============================== */
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int s2t[256], t2s[256];
        fill(begin(s2t), end(s2t), -1);
        fill(begin(t2s), end(t2s), -1);

        for (int i = 0; i < s.size(); i++)
        {
            unsigned char a = s[i];
            unsigned char b = t[i];

            if (s2t[a] == -1 && t2s[b] == -1)
            { // if neither of the letters from s and t are mapped, we'll map them now
                s2t[a] = b;
                t2s[b] = a;
            }
            else if (s2t[a] != b || t2s[b] != a)
            {
                return false;
            }
        }
        return true;
    }
};

bool isIsomorphic_user(const string &s, const string &t)
{
    Solution sol;
    return sol.isIsomorphic(s, t);
}

/* ======================================================
   Brute Force #1: Quadratic check by occurrences pattern
   Time : O(n^2)
   Space: O(1)
====================================================== */
bool isIsomorphic_quadratic(const string &s, const string &t)
{
    if (s.size() != t.size())
        return false;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i)
    {
        char c1 = s[i], c2 = t[i];
        for (int j = 0; j < n; ++j)
        {
            if (s[j] == c1 && t[j] != c2)
                return false;
            if (t[j] == c2 && s[j] != c1)
                return false;
        }
    }
    return true;
}

/* ======================================================
   Brute Force #2: Map + Set (one-to-one constraint)
   -------------------------------------------------
   Maintain a map s->t and a set of already-used t chars.
   Time : O(n) average (unordered_map)
   Space: O(min(Σ, n))  (distinct chars), Σ≈256
====================================================== */
bool isIsomorphic_mapset(const string &s, const string &t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, char> m;
    unordered_set<char> used;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        char a = s[i], b = t[i];
        auto it = m.find(a);
        if (it != m.end())
        {
            if (it->second != b)
                return false;
        }
        else
        {
            if (used.count(b))
                return false;
            m[a] = b;
            used.insert(b);
        }
    }
    return true;
}

int main()
{
    vector<pair<string, string>> tests = {
        {"aab", "xxy"},
        {"foo", "bar"},
        {"paper", "title"},
        {"badc", "baba"},
        {"egg", "add"},
        {"", ""},
        {"ab", "aa"},
        {"13", "42"},
        {"abcd", "ab"}};

    for (auto &[s, t] : tests)
    {
        bool r_user = isIsomorphic_user(s, t);
        bool r_q = isIsomorphic_quadratic(s, t);
        bool r_ms = isIsomorphic_mapset(s, t);

        cout << "s=\"" << s << "\", t=\"" << t << "\" -> "
             << "user: " << (r_user ? "true" : "false")
             << ", quad: " << (r_q ? "true" : "false")
             << ", mapset: " << (r_ms ? "true" : "false")
             << '\n';

        if (!(r_user == r_q && r_q == r_ms))
        {
            cerr << "Mismatch detected on input (" << s << ", " << t << ")\n";
        }
    }
    return 0;
}
