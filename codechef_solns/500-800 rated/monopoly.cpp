#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int P, Q, R, S;
        cin >> P >> Q >> R >> S;

        bool mono = false;

        if (P > Q + R + S)
            mono = true;
        if (Q > P + R + S)
            mono = true;
        if (R > P + Q + S)
            mono = true;
        if (S > P + Q + R)
            mono = true;

        cout << (mono ? "YES" : "NO") << "\n";
    }
}