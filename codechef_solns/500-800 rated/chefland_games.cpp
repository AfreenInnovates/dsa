#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    int T;
    cin >> T;

    while (T--)
    {
        int R1, R2, R3, R4;

        cin >> R1 >> R2 >> R3 >> R4;

        int sum = R1 + R2 + R3 + R4;
        if (sum == 0)
            cout << "IN\n";
        else
            cout << "OUT\n";
    }
}
