#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: frequency sort for ALL characters (lowercase, uppercase, special)

time complexity:
- O(n + k log k)
  - counting frequencies: O(n)
  - pushing to vector: O(k) where k ≤ 256
  - sorting k elements: O(k log k), at most O(256 log 256) = constant
  - building result: O(n)
- overall: O(n)

space complexity:
- O(256) = O(1) extra, since frequency array is fixed size.
- result string O(n) to return.

intuition:
- count how many times each ASCII character appears (0–255).
- put (char, freq) pairs into a vector.
- sort by frequency descending, then by char ascending for ties.
- build the final string by repeating each char its count times.

explanation of:
    size_t total = 0;
    for (auto &p : arr)
        total += static_cast<size_t>(p.second);
    res.reserve(total);

- here we compute the total number of characters in the result (which is
  the original string length n). calling `reserve(n)` pre-allocates memory
  in the string so that repeated `append` calls won’t trigger re-allocations.
  this is just a performance optimization.

explanation of:
    for (auto &p : arr) {
        res.append(static_cast<size_t>(p.second),
                   static_cast<char>(p.first));
    }

- for each (char, freq) pair:
  - `p.second` tells how many times this char should appear.
  - `res.append(count, char)` adds that many copies at once.
  - example: ('e', 2) appends "ee".
*/
string frequencySort_allChars(const string &s)
{
    array<int, 256> freq{};
    freq.fill(0);

    for (unsigned char uc : s)
    {
        freq[uc]++;
    }

    vector<pair<unsigned char, int>> arr;
    arr.reserve(256);

    for (int b = 0; b < 256; b++)
    {
        if (freq[b] > 0)
        {
            arr.push_back({static_cast<unsigned char>(b), freq[b]});
        }
    }

    sort(arr.begin(), arr.end(),
         [](const pair<unsigned char, int> &a,
            const pair<unsigned char, int> &b)
         {
             if (a.second != b.second)
                 return a.second > b.second;
             return a.first < b.first;
         });

    string res;
    size_t total = 0;
    for (auto &p : arr)
        total += static_cast<size_t>(p.second);
    res.reserve(total);

    for (auto &p : arr)
    {
        res.append(static_cast<size_t>(p.second),
                   static_cast<char>(p.first));
    }

    return res;
}

/*
Approach 2: frequency sort for lowercase letters only

time complexity:
- O(n + 26 log 26 + n) = O(n)
  - count frequencies: O(n)
  - sort at most 26 elements: O(1)
  - rebuild string: O(n)

space complexity:
- O(26) = O(1) for freq and vec
- O(n) for result (reusing original string)

intuition:
- since input only has lowercase 'a'..'z', we can use a 26-size array.
- count each character, put (frequency, char) into a vector.
- sort by frequency descending (if needed).
- rebuild the string by placing each character frequency times.

*/
string frequencySort_lowercase(string s)
{
    int n = s.size();
    vector<int> freq(26, 0);

    for (char c : s)
    {
        freq[c - 'a']++;
    }

    vector<pair<int, char>> vec;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            vec.push_back({freq[i], char(i + 'a')});
        }
    }

    sort(vec.begin(), vec.end(), [](auto &a, auto &b)
         {
             if (a.first != b.first)
                 return a.first > b.first; // higher frequency first
             return a.second < b.second;   // tie → smaller char first
         });

    int idx = 0;
    for (auto it : vec)
    {
        int alpha_count = it.first;
        while (alpha_count--)
        {
            s[idx++] = it.second;
        }
    }

    return s;
}

int main()
{
    string s;
    getline(cin, s);

    cout << "Approach 1 (all chars):     " << frequencySort_allChars(s) << "\n";

    bool allLower = all_of(s.begin(), s.end(),
                           [](char c)
                           { return c >= 'a' && c <= 'z'; });
    if (allLower)
    {
        cout << "Approach 2 (lowercase):   " << frequencySort_lowercase(s) << "\n";
    }
    else
    {
        cout << "Approach 2 skipped (input not all lowercase)\n";
    }

    return 0;
}
