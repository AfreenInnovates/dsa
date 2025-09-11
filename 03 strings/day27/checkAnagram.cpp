#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
 * Problem
 * Determine if two given strings are anagrams of each other.
 * Two strings are anagrams if they contain the exact same characters
 * in the same quantity, but possibly in a different order.
 * The task is to return true if they are anagrams, false otherwise.
 */

/*
Approach 1: Sort & Compare
--------------------------
Time  : O(n log n) — sort both strings (n = s.size() = t.size()).
Space : O(n)       — we copy s and t into local buffers to avoid mutating inputs
                     (plus O(log n) recursion stack used by std::sort).
                     (not necessary - can just be return sort(s.begin(), s.end()) == sort(t.begin(), t.end()))
*/
bool isAnagram_sortCompare(const string &s, const string &t)
{
    if (s.size() != t.size())
        return false;
    string a = s, b = t; // local copies so callers' strings stay unchanged
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

/*
Approach 2: Hash Map Frequency (two passes)
-------------------------------------------
Idea: Count chars in s, subtract counts using t, ensure all counts end at zero.

Time  : O(n) average — one pass to add, one to subtract, one to verify.
Space : O(k)         — k = number of distinct characters seen (<= 256/Unicode subset).
*/
bool isAnagram_hashMap(const string &s, const string &t)
{
    if (s.size() != t.size())
        return false;

    unordered_map<char, int> cnt;
    for (char c : s)
        ++cnt[c];
    for (char c : t)
        --cnt[c];

    for (auto &[ch, val] : cnt)
    {
        if (val != 0)
            return false;
    }

    return true;
}

/*
Approach 3: Fixed-Size Array Frequency (ASCII/byte)
---------------------------------------------------
Idea: Use a constant-size array for counts; increment with s, decrement with t.

Time  : O(n) — single pass over indices i.
Space : O(1) — fixed 256-sized array (constant), regardless of input length.
Note  : If the problem restricts to 'a'..'z', you can shrink to 26.
*/
bool isAnagram_fixedArray(const string &s, const string &t)
{
    if (s.size() != t.size())
        return false;

    int freq[256] = {0};
    for (int i = 0; i < (int)s.size(); ++i)
    {
        unsigned char a = s[i];
        unsigned char b = t[i];
        ++freq[a];
        --freq[b];
    }
    for (int v : freq)
    {
        if (v != 0)
            return false;
    }
    return true;
}

int main()
{
    vector<pair<string, string>> tests = {
        {"anagram", "nagaram"},  // true
        {"rat", "car"},          // false
        {"a", "a"},              // true
        {"ab", "a"},             // false
        {"ab", "ba"},            // true
        {"aa", "bb"},            // false
        {"", ""},                // true
        {"Listen", "Silent"},    // case-sensitive -> false
        {"Triangle", "Integral"} // case-sensitive -> false
    };

    for (auto &[s, t] : tests)
    {
        bool r1 = isAnagram_sortCompare(s, t);
        bool r2 = isAnagram_hashMap(s, t);
        bool r3 = isAnagram_fixedArray(s, t);

        cout << "s=\"" << s << "\", t=\"" << t << "\" -> "
             << "sort=" << (r1 ? "true" : "false") << ", "
             << "hash=" << (r2 ? "true" : "false") << ", "
             << "array=" << (r3 ? "true" : "false") << '\n';

        if (!(r1 == r2 && r2 == r3))
        {
            cerr << "Mismatch on input (" << s << ", " << t << ")\n";
        }
    }
    return 0;
}
