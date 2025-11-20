#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    int T;
    cin >> T;

    // total number of working hours in one week would
    // Mon - Thurs : X hours each day -> total 4 * X hours
    // Fri : Y hours -> total Y hours
    // total : (4 * X) + Y
    while (T--)
    {
        int X, Y;

        cin >> X >> Y;

        cout << (4 * X) + Y << "\n";
    }
}
