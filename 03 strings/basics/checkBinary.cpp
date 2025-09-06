#include <bits/stdc++.h>
using namespace std;

/*
 * Function: isBinary
 * Checks if a string contains only '0' and '1'.
 *
 * Time Complexity:  O(n)  — traverses the string once
 * Space Complexity: O(1)  — uses only a few extra variables
 */
bool isBinary(const string &s)
{
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] != '0' && s[i] != '1')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    if (isBinary(str))
        cout << "Yes, it is a binary string ✅" << endl;
    else
        cout << "No, it is NOT a binary string ❌" << endl;

    return 0;
}
