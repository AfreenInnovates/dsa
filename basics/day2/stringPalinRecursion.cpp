#include <bits/stdc++.h>
using namespace std;

string palin(string str, int i)
{
    if (i < 0)
        return "";

    return str[i] + palin(str, i - 1);
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    int i = str.length();

    transform(str.begin(), str.end(), str.begin(), ::tolower); // ref.: https://www.geeksforgeeks.org/cpp/how-to-convert-std-string-to-lower-case-in-cpp/

    string rev = palin(str, i - 1);

    if (rev == str)
    {
        cout << "Palindrome";
    }
    else
        cout << "Not palindrome";
}