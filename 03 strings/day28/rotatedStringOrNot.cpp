#include <iostream>
#include <string>
using namespace std;

bool rotateString(string s, string goal)
{
    if (s.length() != goal.length())
        return false;

    string concatenatedString = s + s;

    return concatenatedString.find(goal) < concatenatedString.length();
}

int main()
{
    string s = "abcde";
    string goal = "cdeab";

    if (rotateString(s, goal))
    {
        cout << goal << " is a rotation of " << s << endl;
    }
    else
    {
        cout << goal << " is NOT a rotation of " << s << endl;
    }

    return 0;
}