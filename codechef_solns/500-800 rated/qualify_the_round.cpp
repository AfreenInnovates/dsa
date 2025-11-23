#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // easy - 1 point
    // hard - 2 points

    // (total points by chef) = (a*1) + (b*2)
    // if total > x qualify else not

    int T;
    cin >> T;

    while (T--)
    {
        int X, A, B;
        cin >> X >> A >> B;

        int total = A * 1 + B * 2;

        if (total >= X)
            cout << "Qualify\n";
        else
            cout << "NotQualify\n";
    }
}
