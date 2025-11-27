#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<long long> copy_a = a;
        sort(copy_a.begin(), copy_a.end()); // if same as a, then we can sort

        if (a == copy_a || k > 1)
            cout
                << "YES\n";
        else
            cout << "NO\n";
    }
}