#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (long long k = 1; k <= n; k++)
    {
        long long total_cells = k * k;
        long long total_pairs = total_cells * (total_cells - 1) / 2;

        long long attacking_positions = 0;
        if (k > 2)
            attacking_positions = 4LL * (k - 1) * (k - 2);

        long long valid_positions = total_pairs - attacking_positions;

        cout << valid_positions << "\n";
    }
}
