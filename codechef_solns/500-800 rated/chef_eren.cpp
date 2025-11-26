#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, A, B;
        cin >> N >> A >> B;

        int odd = (N + 1) / 2;
        int even = N / 2;

        long long total = odd * B + even * A;

        cout << total << "\n";
    }
}
