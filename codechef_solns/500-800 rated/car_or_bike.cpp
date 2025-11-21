#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here

    int T;
    cin >> T;

    while (T--)
    {
        int X, Y;
        cin >> X >> Y;

        // X ->BIKE
        // Y -> CAR

        if (X > Y)
            cout << "CAR\n";
        else if (X < Y)
            cout << "BIKE\n";
        else
            cout << "SAME\n";
    }
}