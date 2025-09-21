#include <bits/stdc++.h>
using namespace std;

bool checkPalin(int i, int n, string word)
{
    if (i >= n / 2)
        return true;
    if (word[i] != word[n - i - 1])
        return false;

    return checkPalin(i + 1, n, word);
}

int main()
{
    cout << "Enter word to check: " << endl;
    string word;
    cin >> word;

    int n = word.length();

    if (checkPalin(0, n, word))
        cout << word << " is a palindrome" << endl;
    else
        cout << word << " is not a palindrome" << endl;

    return 0;
}

// int main()
// {
//     cout << "Enter word to check: " << endl;
//     string word;
//     getline(cin, word); // ✅ allows spaces

//     int n = word.length();

//     if (checkPalin(0, n, word))
//         cout << "\"" << word << "\" is a palindrome ✅" << endl;
//     else
//         cout << "\"" << word << "\" is not a palindrome ❌" << endl;

//     return 0;
// }