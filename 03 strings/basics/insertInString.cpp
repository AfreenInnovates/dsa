#include <bits/stdc++.h>
using namespace std;

string returnNewString(string s, char ch, int pos)
{
    string result = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (i == pos)
        {
            result.push_back(ch);
        }
        else
        {
            result.push_back(s[i]);
        }
    }

    // If pos is beyond the string length, append at the end
    if (pos >= s.length())
    {
        result.push_back(ch);
    }
    return result;
}

int main()
{
    string str;
    char ch;
    int pos;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter a character to insert: ";
    cin >> ch;

    cout << "Enter position (0-based index): ";
    cin >> pos;

    if (pos < 0)
    {
        cout << "Invalid position" << endl;
    }
    else
    {
        string newStr = returnNewString(str, ch, pos);
        cout << "New string: " << newStr << endl;
    }

    return 0;
}
