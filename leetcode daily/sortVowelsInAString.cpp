#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Sort Vowels in a String

- Rearrange all vowels (a, e, i, o, u, A, E, I, O, U) in sorted order.
- Non-vowel characters remain in their original positions.
- Example: "leetcode" -> "leetcdoe"
*/

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

/*
- Collect all vowels in a temporary string `temp`.
- Sort the vowels.
- Reconstruct the original string:
  * If character is not vowel → copy as is.
  * If character is vowel → take from sorted `temp`.

Time  : O(n log n)
    In the worst case, all characters in the string s could be vowels, and we will have to sort all the N characters which takes O(NlogN) time. In the end, we will iterate over the string s and build the string ans, this will take O(N) time. Therefore, the total time complexity is equal to O(NlogN).
Space : O(n) — extra space for `temp` storing vowels and `ans` storing final string
*/
string sortVowels(string s)
{
    string temp;
    for (char c : s)
    {
        if (isVowel(c))
        {
            temp += c;
        }
    }

    sort(temp.begin(), temp.end());

    int j = 0;
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        if (!isVowel(s[i]))
        {
            ans += s[i];
        }
        else
        {
            ans += temp[j++];
        }
    }

    return ans;
}

int main()
{
    vector<string> tests = {
        "leetcode",
        "hello world",
        "AEiou",
        "Programming is fun",
        "xyz"};

    for (const auto &s : tests)
    {
        string result = sortVowels(s);
        cout << "Original : \"" << s << "\"\n";
        cout << "Sorted Vowels : \"" << result << "\"\n\n";
    }

    return 0;
}
