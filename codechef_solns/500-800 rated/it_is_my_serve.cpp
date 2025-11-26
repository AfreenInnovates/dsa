#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int P, Q;
        cin >> P >> Q;

        int S = P + Q;     // total points played
        int block = S / 2; // which 2-serve block we are in

        if (block % 2 == 0)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
}
