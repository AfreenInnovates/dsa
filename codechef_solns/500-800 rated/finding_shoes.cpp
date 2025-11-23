#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // m is number of left shoes
    // is m>=n, then we need n right shoes
    // if m < n, then we have m left shoes => needed more left shoes would be n-m
    // and needed right shoes would be n
    // so total n-m+n =2n-m

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        if (m >= n)
            cout << n << endl;
        else
            cout << (2 * n - m) << endl;
    }
}
