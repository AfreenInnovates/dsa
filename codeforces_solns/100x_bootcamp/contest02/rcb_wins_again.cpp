// After winning the IPL, RCB is posing for a victory photo. But instead of standing in the usual order, the captain wants a formation that feels perfectly symmetric.

// The arrangement is defined as follows:

// Start from the two middle players.
// Then move one step outward on both sides.
// Print the next outward pair.
// Continue until all players are included.
// You must print the players in this order:

// middle-left, middle-right, then expanding outward by alternating left and right, until the entire array is covered.

// 6
// 10 20 30 40 50 60
// n=6
//n/2 = 3
//n/2 - 1 = 2
// print a[2], a[3]
// 30 40
// print a[1], a[4]
// 30 40 20 50
// print a[0], a[5]
// 30 40 20 50 10 60


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int L = (n - 1) / 2;
    int R = n / 2;

    while (L >= 0 || R < n) {
         cout << a[L] << " ";
        cout << a[R] << " ";
        L--;R++;
    }

    return 0;
}
