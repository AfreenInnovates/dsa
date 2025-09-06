#include <bits/stdc++.h>
using namespace std;

// time : O(N)
// space : O(1)
bool checkStrings(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

int main()
{
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);

    cout << "Enter second string: ";
    getline(cin, str2);

    if (checkStrings(str1, str2))
        cout << "Strings are equal" << endl;
    else
        cout << "Strings are NOT equal" << endl;

    return 0;
}
