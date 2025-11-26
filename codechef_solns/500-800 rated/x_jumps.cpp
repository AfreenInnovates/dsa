#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int X, Y;
        cin >> X >> Y;

        int big = X / Y;       // number of Y-step jumps
        int rem = X % Y;       // remaining steps
        int moves = big + rem; // 1-step moves cover the rest

        cout << moves << endl;
    }
}
