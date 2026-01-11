#include <bits/stdc++.h>
using namespace std;

/*

Time Complexity:  O(n)
Space Complexity: O(n)
*/
string reverseWords_vector(string s)
{
    vector<string> words;
    string cur = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            cur.push_back(s[i]);
        }
        else
        {
            if (!cur.empty())
            {
                words.push_back(cur);
                cur = "";
            }
        }
    }

    if (!cur.empty())
        words.push_back(cur);

    reverse(words.begin(), words.end());

    string res = "";
    for (int i = 0; i < words.size(); i++)
    {
        res += words[i];
        if (i != words.size() - 1)
            res += " ";
    }

    return res;
}

/*

Time Complexity:  O(n)
Space Complexity: O(n)
*/
string reverseWords_reverseTechnique(string s)
{
    int n = s.length();
    string ans = "";

    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++)
    {
        string word = "";

        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());

        if (word.length() > 0)
            ans += " " + word;
    }

    return ans.substr(1);
}

int main()
{
    string s = "  the sky   is blue  ";

    cout << "Input: \"" << s << "\"\n\n";

    cout << "Using vector method:        ";
    cout << "\"" << reverseWords_vector(s) << "\"\n";

    cout << "Using reverse technique:    ";
    cout << "\"" << reverseWords_reverseTechnique(s) << "\"\n";

    return 0;
}
