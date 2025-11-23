#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // x geyser litres
    // y litres in one bucket

    // one person needs = 2*y litres of water = needed_litres

    // if needed_litres > x then no one can take bath
    // else needed_litres / x

    int t;
    cin >> t;

    while (t--)
    {
        int X, Y;
        cin >> X >> Y;

        int needed = 2 * Y;
        int people = X / needed;

        cout << people << endl;
    }
}
