#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        // if room number is a multiple of 10, then floor number is room number / 10
        // otherwise, (room number / 10) + 1
        int fx = (x % 10 == 0) ? (x / 10) : ((x / 10) + 1);
        int fy = (y % 10 == 0) ? (y / 10) : ((y / 10) + 1);

        cout << abs(fx - fy) << '\n';
    }
    return 0;
}
