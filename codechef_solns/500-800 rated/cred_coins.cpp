#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // Y -> number of bills paid using CRED
    // X -> CRED coins earned

    // 1 bag = 100 CRED coins

    // we find number of CRED coins earned by
    // no. of bills * CRED coins
    // Y * X

    // no. of bags = (Y*X) / 100   (get the quotient)

    int T;
    cin >> T;

    while (T--)
    {
        int X, Y;

        cin >> X >> Y;

        int total_cred_coins = Y * X;

        int no_of_bags = (total_cred_coins) / 100;

        cout << no_of_bags << endl;
    }
}
