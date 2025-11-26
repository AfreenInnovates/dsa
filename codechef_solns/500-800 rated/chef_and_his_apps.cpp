#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int S, X, Y, Z;
        cin >> S >> X >> Y >> Z;

        int free = S - (X + Y);

        if (free >= Z)
        {
            cout << 0 << "\n";
        }
        else if (S - X >= Z || S - Y >= Z)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 2 << "\n";
        }
    }
}
