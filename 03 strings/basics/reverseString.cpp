#include <bits/stdc++.h>
using namespace std;

/*
 * Method 1: Two-pointer swap
 * Time:  O(n)
 * Space: O(1)
 */
string reversedString(string s)
{
    int i = 0, j = (int)s.size() - 1;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}

/*
 * Method 2: Using std::reverse from <algorithm>
 * Time:  O(n)
 * Space: O(1)
 */
string reverseWithAlgorithm(string s)
{
    reverse(s.begin(), s.end());
    return s;
}

/*
 * Method 3: Build a new string by iterating backwards
 * Time:  O(n)
 * Space: O(n)
 */
string reverseByBuilding(string s)
{
    string result = "";
    for (int i = (int)s.size() - 1; i >= 0; i--)
    {
        result.push_back(s[i]);
    }
    return result;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "\n--- Reverse String Methods ---\n";
    cout << "1) Two-pointer swap    : " << reversedString(str) << '\n';
    cout << "2) std::reverse        : " << reverseWithAlgorithm(str) << '\n';
    cout << "3) Build backwards     : " << reverseByBuilding(str) << '\n';

    return 0;
}
