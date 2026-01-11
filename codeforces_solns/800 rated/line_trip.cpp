#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int max_gap = a[0];  // distance from 0 to first station

        // distances between consecutive stations
        for (int i = 1; i < n; i++) {
            max_gap = max(max_gap, a[i] - a[i - 1]);
        }

        // last ride needs to be covered twice
        max_gap = max(max_gap, 2 * (x - a[n - 1]));

        cout << max_gap << "\n";
    }

    return 0;
}
