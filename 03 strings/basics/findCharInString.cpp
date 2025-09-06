#include <bits/stdc++.h>
using namespace std;

// time : O(N)
// space : O(1)
bool checkChar(string s, char ch)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ch)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string str;
    char ch;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter a character to search: ";
    cin >> ch;

    if (checkChar(str, ch))
        cout << "Character '" << ch << "' found in string " << endl;
    else
        cout << "Character '" << ch << "' not found in the string" << endl;

    return 0;
}
