#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    int t;
    cin >> t;
    while (t--)
    {
        int n, x, a, c = 0;
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a >= x)
                c++;
        }
        cout << c << endl;
    }
}
