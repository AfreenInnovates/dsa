#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // we can take max of a,b and then max of c,d and then sum it
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int max_first, max_second;

        if (a > b)
            max_first = a;
        else
            max_first = b;

        if (c > d)
            max_second = c;
        else
            max_second = d;

        int sum = max_first + max_second;

        cout << sum << endl;
    }
}
