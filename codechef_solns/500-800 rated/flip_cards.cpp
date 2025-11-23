#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // n cards
    // x are face up
    // n-x are face down

    // so if x is greater, then n-x or x

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        if (x > (n - x))
            cout << (n - x) << endl;
        else
            cout << x << endl;
    }
}
