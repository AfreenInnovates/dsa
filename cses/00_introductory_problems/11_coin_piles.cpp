#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        long long mx = max(a, b);
        long long mn = min(a, b);

        // cond 1: total divisible by 3
        // cond 2: no pile is more than double the other
        if ((a + b) % 3 == 0 && mx <= 2 * mn)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
