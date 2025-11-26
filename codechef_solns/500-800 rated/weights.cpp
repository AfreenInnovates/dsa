#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int W, X, Y, Z;
        cin >> W >> X >> Y >> Z;

        bool ok = false;

        if (X == W)
            ok = true;
        if (Y == W)
            ok = true;
        if (Z == W)
            ok = true;

        if (X + Y == W)
            ok = true;
        if (X + Z == W)
            ok = true;
        if (Y + Z == W)
            ok = true;

        if (X + Y + Z == W)
            ok = true;

        cout << (ok ? "YES" : "NO") << "\n";
    }
}
