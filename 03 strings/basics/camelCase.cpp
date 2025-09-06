#include <bits/stdc++.h>
using namespace std;

/*
 * Function: convertToCamelCase
 * Converts a space-separated string into camelCase style:
 * - The first word stays lowercase
 * - Each subsequent word starts with an uppercase letter
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */
string convertToCamelCase(string s)
{
    string result = "";
    bool capitalize = false;

    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == ' ')
        {
            capitalize = true; // mark next character for uppercase
        }
        else if (capitalize)
        {
            result += toupper(s[i]);
            capitalize = false; // reset after capitalizing
        }
        else
        {
            result += tolower(s[i]); // keep lowercase for normal flow
        }
    }
    return result;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string camel = convertToCamelCase(str);
    cout << "CamelCase: " << camel << endl;

    return 0;
}
