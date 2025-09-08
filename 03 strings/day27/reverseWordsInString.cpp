#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Approach A: Collect words, then join in reverse
------------------------------------------------------------------------------
- Parse s with a single for-loop:
  * Build the current word character-by-character.
  * On a space, if we have a non-empty word, push it and clear.
  * After the loop, push the final word if non-empty.
- Build the result by iterating the collected words in reverse and inserting
  a single space between them.

Time  : O(n) — each character is visited a constant number of times
                 (collect + final join).
Space : O(n) extra — we store all words in a vector and also create the output
                     string. (Auxiliary space excluding the output is O(n).)
*/
string reverseWords_collectAndReverse(const string &s)
{
    vector<string> words;
    string current;

    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] == ' ')
        {
            if (!current.empty())
            {
                words.push_back(current);
                current.clear();
            }
        }
        else
        {
            current += s[i];
        }
    }
    if (!current.empty())
        words.push_back(current);

    string res;
    for (int i = (int)words.size() - 1; i >= 0; --i)
    {
        res += words[i];
        if (i > 0)
            res += ' ';
    }
    return res;
}

/*
Approach B: In-place optimal (normalize spaces -> reverse all -> reverse each word)
-----------------------------------------------------------------------------------
Steps (all in-place, only for-loops, no while):
1) Normalize spaces:
   - Remove leading/trailing spaces and collapse multiple spaces to one.
   - Use a read index and a write index in a single pass.
2) Reverse the entire string.
3) Reverse each word (scan with a single for-loop and reverse on word boundaries).

Time  : O(n) — each character is moved a constant number of times across the steps.
Space : O(1) extra — all operations are done in the same string buffer; no extra
                     containers beyond a few indices (excluding the output string).

*/
string reverseWords_inPlace(string s)
{
    // 1) Normalize spaces in-place
    int writePos = 0;
    bool wroteSpaceLast = true; // treat "before start" as space to drop leading spaces
    for (int readPos = 0; readPos < (int)s.size(); ++readPos)
    {
        if (s[readPos] != ' ')
        {
            s[writePos++] = s[readPos];
            wroteSpaceLast = false;
        }
        else if (!wroteSpaceLast)
        {
            s[writePos++] = ' ';
            wroteSpaceLast = true;
        }
    }
    if (writePos > 0 && s[writePos - 1] == ' ')
        --writePos; // drop trailing space
    s.resize(writePos);

    // 2) Reverse whole string
    reverse(s.begin(), s.end());

    // 3) Reverse each word
    int wordStart = 0;
    for (int i = 0; i <= (int)s.size(); ++i)
    {
        if (i == (int)s.size() || s[i] == ' ')
        {
            reverse(s.begin() + wordStart, s.begin() + i);
            wordStart = i + 1;
        }
    }
    return s;
}

int main()
{
    vector<string> tests = {
        "",
        "a",
        "  hello  world  ",
        "the sky is   blue",
        "   multiple   spaces   everywhere   ",
        "leetcode"};

    for (const auto &s : tests)
    {
        string rA = reverseWords_collectAndReverse(s);
        string rB = reverseWords_inPlace(s);

        cout << "s:  \"" << s << "\"\n";
        cout << "A : \"" << rA << "\"\n";
        cout << "B : \"" << rB << "\"\n\n";

        assert(rA == rB);
    }

    cout << "All tests passed.\n";
    return 0;
}
