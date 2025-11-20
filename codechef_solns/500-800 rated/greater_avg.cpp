#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int T;
    cin >> T;

    int A, B, C;

    while (T--)
    {
        cin >> A >> B >> C;

        if (((A + B) / 2.0) > C)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
