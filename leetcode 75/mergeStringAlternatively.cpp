/*
Problem: Merge Strings Alternately
https://leetcode.com/problems/merge-strings-alternately/description/
---------------------------------------------------
You are given two strings word1 and word2.
Merge the strings by adding letters in alternating order,
starting with word1. If a string is longer than the other,
append the remaining letters at the end.

Example:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
*/

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Original Naive (3 while loops)
--------------------------------------------
- Append alternately using 3 while loops:
  1. Loop till min(size1, size2)
  2. Append remaining of word1
  3. Append remaining of word2
- Time Complexity: O(n + m)
- Space Complexity: O(n + m) (output string)
*/
string mergeAlternately_approach1(string word1, string word2)
{
    string merged = "";
    int i = 0;
    int size1 = word1.size(), size2 = word2.size();
    int mini = min(size1, size2);

    while (i < mini)
    {
        merged += word1[i];
        merged += word2[i];
        i++;
    }

    while (i < size1)
    {
        merged += word1[i];
        i++;
    }

    while (i < size2)
    {
        merged += word2[i];
        i++;
    }

    return merged;
}

/*
Approach 2: Single for-loop naive
----------------------------------
- Use a single for-loop up to max(size1, size2)
- Append each character if index is in bounds
- Time Complexity: O(n + m) (still possible repeated reallocations)
- Space Complexity: O(n + m)
*/
string mergeAlternately_approach2(string word1, string word2)
{
    string merged = "";
    int n = max(word1.size(), word2.size());

    for (int i = 0; i < n; i++)
    {
        if (i < word1.size())
            merged += word1[i];
        if (i < word2.size())
            merged += word2[i];
    }

    return merged;
}

/*
Approach 3: Optimized (reserve + push_back + append)
-----------------------------------------------------
- Reserve memory upfront to avoid repeated reallocations
- Use push_back for single characters
- Append remaining characters in one shot using substr
- Time Complexity: O(n + m)
- Space Complexity: O(n + m)
*/
string mergeAlternately_approach3(string word1, string word2)
{
    int size1 = word1.size(), size2 = word2.size();
    string merged;
    merged.reserve(size1 + size2);

    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        merged.push_back(word1[i++]);
        merged.push_back(word2[j++]);
    }

    if (i < size1)
        merged.append(word1.substr(i));
    if (j < size2)
        merged.append(word2.substr(j));

    return merged;
}

int main()
{
    string word1 = "abc";
    string word2 = "pqrstu";

    cout << "Original Naive Merge: " << mergeAlternately_approach1(word1, word2) << endl;
    cout << "For-loop Naive Merge: " << mergeAlternately_approach2(word1, word2) << endl;
    cout << "Optimized Merge:      " << mergeAlternately_approach3(word1, word2) << endl;

    return 0;
}
