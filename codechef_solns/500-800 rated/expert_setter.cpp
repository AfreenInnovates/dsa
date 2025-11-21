#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // expert -> 50% of problems approved by Chef
    // X -> no. of problems
    // Y -> approved

    // so (Y/X)*100 >= 50
    // but that would give answer as 0 at times (Y/X)
    // so the double of Y must be greater than equal to X

    // ex. : 5 input
    // needed 3
    // 3/5 -> 0
    // but 3*3 = 6 > 5

    int T;
    cin >> T;

    while (T--)
    {
        int X, Y;
        cin >> X >> Y;

        if (Y * 2 >= X)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
