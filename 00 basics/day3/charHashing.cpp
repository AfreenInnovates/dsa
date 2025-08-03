#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;

    // creating the hash array
    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[int(s[i])] += 1;
        // ex.:
        // s[0] = a
        // hash[s[0]] = hash[a] = 1
    }

    int num;
    cout << "Enter number of characters you want to enter: ";
    cin >> num;
    while (num--)
    {
        char ch;
        cout << "Enter character: ";
        cin >> ch;

        cout << ch << " occurs " << hash[int(ch)] << " times." << endl;
    }
}