#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // alice current rating -> X
    // when she wins -> X + 8 (per game)
    // to make her rating >= Y
    // so how many of 8(pergame)+X >= Y
    // let how many = k
    // 8k+X = Y
    // k = (Y-X)/8

    int t;
    cin >> t;
    while (t--)
    {
        int X, Y;
        cin >> X >> Y;

        int diff = Y - X;
        int games = (diff + 7) / 8;

        cout << games << endl;
    }
}
