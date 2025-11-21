#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // X grams of He-3
    // 1 gram of He-3 can provide Y units
    // X grams -> X*Y units

    // so X*Y > A*B

    int T;
    cin >> T;
    while (T--)
    {
        int X, Y, A, B;
        cin >> A >> B >> X >> Y;

        if (X * Y >= A * B)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
