#include <bits/stdc++.h>
using namespace std;

/*
 * removeAllChars
 * Time Complexity:  O(n) — single pass over the string
 * Space Complexity: O(n) — builds a separate result string
 */
void removeAllChars(string s, char ch)
{
    string result = "";
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] != ch)
        {
            result.push_back(s[i]);
        }
    }
    cout << "After removing all (new buffer): " << result << '\n';
}

/*
 * twoPointers
 * Time Complexity:  O(n) — single pass with two indices
 * Space Complexity: O(1) — in-place
 */
void twoPointers(string s, char ch)
{
    int j = 0;
    cout << "--- twoPointers Dry Run ---\n";
    for (int i = 0; i < (int)s.size(); i++)
    {
        cout << "i = " << i << ", j = " << j << ", s[i] = '" << s[i] << "' -> ";
        if (s[i] != ch)
        {
            s[j++] = s[i];
            cout << "kept, s = \"" << s << "\"\n";
        }
        else
        {
            cout << "removed, s = \"" << s << "\"\n";
        }
    }
    s.resize(j);
    cout << "Final Result: " << s << "\n";
}

int main()
{
    string str;
    char ch;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter a character to remove: ";
    cin >> ch;

    removeAllChars(str, ch);

    twoPointers(str, ch);

    return 0;
}
