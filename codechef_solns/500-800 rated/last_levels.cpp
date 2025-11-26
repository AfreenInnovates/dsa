#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here

    // X levels remaining
    // 1 level -> Y mins
    // X levels -> Y * X mins
    // every 3 levels, take break

    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        if (x <= 3)
        { // if less than 3 levels remain
            cout << x * y << endl;
        }
        else if (x % 3 == 0)
        {
            int n = (((x / 3) - 1) * z) + (x * y);
            cout << n << endl;
        }
        else
        {
            cout << ((x / 3) * z) + (x * y) << endl;
        }
    }
}