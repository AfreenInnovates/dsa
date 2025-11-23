#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int c = 0;
        c = n / 4;

        if (n % 4 != 0)
        {
            c = n / 4;
            c += 1;
        }

        cout << c << endl;
    }
}
