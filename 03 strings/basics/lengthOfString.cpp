#include <bits/stdc++.h>
using namespace std;

int lengthOfString(const string &s)
{
    int i = 0, count = 0;

    while (s[i])
    {
        i++;
        count++;
    }
    return count;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    cout << "Length of string: " << lengthOfString(input) << endl;

    return 0;
}
