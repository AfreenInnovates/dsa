#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here

    // 1kg pulp -> 1000 pages
    // 1 notebook -> 100 pages
    // 1kg pulp -> 10 notebooks

    // N kg of pulp = 10*N notebooks

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        cout << 10 * N << "\n";
    }

    return 0;
}