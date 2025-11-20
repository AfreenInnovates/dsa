#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // three bottles
    // if two empty (0) -> "Water filling time"    (sum would be 1 or less)
    // if 1 or less empty -> "Not now"   (sum of three would be 2 or more)

    // empty - 0
    // full - 1
    // sum them up
    // sum <= 1 ""

    int T;
    cin >> T;

    while (T--)
    {
        int B1, B2, B3;

        cin >> B1 >> B2 >> B3;

        int sum = B1 + B2 + B3;

        if (sum <= 1)
            cout << "Water filling time\n";
        else
            cout << "Not now\n";
    }
}
