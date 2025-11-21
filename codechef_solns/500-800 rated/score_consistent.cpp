#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {

        int A, B, C, D;
        cin >> A >> B; // initial score A:B
        cin >> C >> D; // final score C:D

        // score can only increase
        // so C must be >= A and D must be >= B

        if (C >= A && D >= B)
            cout << "POSSIBLE\n";
        else
            cout << "IMPOSSIBLE\n";
    }
}