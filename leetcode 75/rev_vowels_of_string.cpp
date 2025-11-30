#include <bits/stdc++.h>
using namespace std;

class TwoPointerSolution
{
    // time : O(n)
    // space : O(1)
public:
    bool isVowel(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s)
    {

        int left = 0, right = s.size() - 1;

        while (left < right)
        {

            // both pointers are on vowels → swap them
            if (isVowel(s[left]) && isVowel(s[right]))
            {
                swap(s[left], s[right]);
                left++;
                right--;
                continue; // move to next iteration
            }

            // if letter at left position is vowel, but right is not, then we move right backwards
            if (isVowel(s[left]) && !isVowel(s[right]))
            {
                right--;
                continue;
            }

            // letter at left position is not vowel, but at right is, so we move left forward
            if (!isVowel(s[left]) && isVowel(s[right]))
            {
                left++;
                continue;
            }

            // if both not vowels
            if (!isVowel(s[left]) && !isVowel(s[right]))
            {
                left++;
                right--;
            }
        }

        return s;
    }
};

// time : n + n + n = 3n → O(n)
// space : n (indices) + n (chars) = 2n → O(n)
string arrayApproach(string s)
{
    vector<int> idx;
    string chars;

    auto isVowel = [](char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };

    // storing all the vowels, and its index positions
    for (int i = 0; i < s.size(); i++)
    {
        if (isVowel(s[i]))
        {
            chars.push_back(s[i]);
            idx.push_back(i);
        }
    }

    // We do NOT touch the indices, those stay in original order
    // After reversing, chars[j] corresponds to the vowel that should go to idx[j]
    reverse(chars.begin(), chars.end());

    // overwrite the characters at the stored vowel indices with reversed ones.
    for (int j = 0; j < idx.size(); j++)
    {
        s[idx[j]] = chars[j];
    }

    return s;
}

// --------------------------------------------------------------------------

int main()
{
    string s;
    cin >> s;

    TwoPointerSolution tps;

    cout << "Two Pointer Output: " << tps.reverseVowels(s) << "\n";
    cout << "Array Approach Output: " << arrayApproach(s) << "\n";

    return 0;
}
