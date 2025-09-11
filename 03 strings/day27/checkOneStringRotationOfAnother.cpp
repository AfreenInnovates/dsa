#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * Problem
 * -------
 * Check whether one string can be rotated to become another string.
 * A rotation means shifting characters in order (e.g., "abcde" -> "cdeab").
 * Return true if the second string is a rotation of the first, false otherwise.
 */

/*
Approach 1: Try all rotations using std::rotate
Time : O(n^2)  -> n rotations, each rotation costs O(n)
Space: O(1)    -> in-place rotation
*/
bool rotateString_byRotating(string s, const string &goal)
{
    if (s.length() != goal.length())
        return false;
    int length = (int)s.length();

    for (int rotationCount = 0; rotationCount < length; ++rotationCount)
    {
        rotate(s.begin(), s.begin() + 1, s.end()); // one left shift
        if (s == goal)
            return true;
    }
    return false;
}

/*
Approach 2: Check if goal is a substring of s+s. In most cases the rotated string is a substring of the concatenated string. So its length also must be less than s + s
Time : O(n) average (depends on find implementation), worst-case can degrade
Space: O(n) for the concatenated string (s+s)
// example : abcde
// s + s : abcdeabcde
// check for cdeab
// which is a substring of s + s
*/
bool rotateString_substringCheck(const string &s, const string &goal)
{
    if (s.length() != goal.length())
        return false;
    string concatenatedString = s + s;
    return concatenatedString.find(goal) < concatenatedString.length(); // equivalent to != npos
}

int main()
{
    vector<pair<string, string>> tests = {
        {"abcde", "cdeab"},
        {"abcde", "abced"},
        {"", ""},
        {"a", "a"},
        {"aa", "aa"},
        {"aa", "ab"},
        {"rotation", "tationro"},
        {"zzz", "zzz"},
    };

    for (auto &[s, goal] : tests)
    {
        bool r1 = rotateString_byRotating(s, goal);
        bool r2 = rotateString_substringCheck(s, goal);
        cout << "s=\"" << s << "\", goal=\"" << goal << "\" -> "
             << "rotate: " << (r1 ? "true" : "false")
             << ", s+s find: " << (r2 ? "true" : "false")
             << '\n';
    }
    return 0;
}
