#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // N water bottles are empty
    // 1 water bottle -> X litres
    // N water bottles -> N*X litres needed
    // in water tank -> K litres of water
    // needed: N*X litres
    // is there: K litres
    // 1 bottle -> X litres
    // ? bottles -> K litres
    // K/X bottles
    // so we can fill upto K/X bottles
    // but chef has only N bottles
    // so whatever is the min of both can be filled
    int t;
    cin >> t;
    while (t--)
    {
        int N, X, K;
        cin >> N >> X >> K;

        int can_fill = K / X;
        cout << min(N, can_fill) << endl;
    }
}
