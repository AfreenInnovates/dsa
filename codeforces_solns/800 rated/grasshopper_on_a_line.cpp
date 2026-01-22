// if x is not divisible by k, then we can reach x in one jump.
// if x is divisible by k, then one jump is not possible.
// so we split x into two jumps: 1 and (x - 1).
// why this works:
// 1 is not divisible by any k (k >= 2), so the first jump is always valid.
// since x is divisible by k, x - 1 cannot be divisible by k.
// reducing a number divisible by k by 1 makes it non-divisible by k.
// hence, both jumps are valid and their sum is exactly x.
// therefore, two jumps are always enough in this case.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x, k;
        cin >> x >> k;

        // x is not divisible by k, so in one jump
        if (x % k != 0)
        {
            cout << 1 << endl;
            cout << x << endl;
        }
        else
        {
            // x is divisible by k
            // two jumps: 1 and (x - 1)
            cout << 2 << endl;
            cout << 1 << " " << x - 1 << endl;
        }
    }
    return 0;
}
