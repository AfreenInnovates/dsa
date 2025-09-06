#include <bits/stdc++.h>
using namespace std;

void removeFromString(string s, char ch)
{
    string result = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ch)
        {
            result.push_back(s[i]);
        }
    }

    cout << "New string after removing '" << ch << "' is: " << result << endl;
}

int main()
{
    string str;
    char ch;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter a character to remove: ";
    cin >> ch;

    removeFromString(str, ch);

    return 0;
}
