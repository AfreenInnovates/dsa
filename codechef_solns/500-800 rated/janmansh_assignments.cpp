#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int startPM;
        cin >> startPM;

        if (10 - startPM >= 3)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}
