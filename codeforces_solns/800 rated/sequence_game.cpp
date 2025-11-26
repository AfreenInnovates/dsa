#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        long long mn = LLONG_MAX, mx = LLONG_MIN;
        long long a;

        for (int i = 0; i < n; i++)
        {
            cin >> a;
            mn = min(mn, a);
            mx = max(mx, a);
        }

        long long x;
        cin >> x;

        if (x >= mn && x <= mx)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}