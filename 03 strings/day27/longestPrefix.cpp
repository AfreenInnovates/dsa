#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * Problem
 * -------
 * Given an array of strings, find the longest common prefix among them.
 * The prefix must appear at the start of every string.
 * If no common prefix exists, return an empty string.
 */

//
//

/*  * Time Complexity:
 *  - Worst case: O(n * L^2)
 *    - n = number of strings
 *    - L = length of the first string (or maximum possible prefix)
 *    - For each string, the prefix may shrink from length L down to 0.
 *      Each shrink involves substr() and find(), each taking O(L) time.
 *  - Best case: O(n * L)
 *    - All strings share the full prefix; inner loop runs once per string.
 *
 * Space Complexity:
 *  - O(L)
 *    - Only stores the prefix string (at most length L)
 */
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
    {
        return "";
    }

    string prefix = strs[0];

    for (int i = 1; i < (int)strs.size(); ++i)
    {
        while (strs[i].find(prefix) != 0) // checks if str[i] starts with prefix
        {
            prefix = prefix.substr(0, prefix.length() - 1); // substr(start, length) -> start: starting index, length -> how many characters to take

            if (prefix.empty())
            {
                return "";
            }
        }
    }

    return prefix;
}

static void printVec(const vector<string> &v)
{
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << "\"" << v[i] << "\"";
        if (i + 1 < v.size())
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    vector<vector<string>> tests = {
        {"flower", "flow", "flight"},
        {"dog", "racecar", "car"},
        {"interspecies", "interstellar", "interstate"},
        {"", "a"},
        {"alone"},
        {}};

    for (auto strs : tests)
    {
        cout << "Input: ";
        printVec(strs);
        cout << "\n";
        string res = longestCommonPrefix(strs);
        cout << "Output: \"" << res << "\"\n";
        cout << "--------------------------------------\n";
    }
    return 0;
}
