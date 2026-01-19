#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        long long best = 0, cur = 0;

        for (int i = 0; i < (int)a.size(); i++) {
            if (i == 0 || a[i] != a[i - 1] + 1) {
                cur = 1;
            } else {
                cur++;
            }
            best = max(best, cur);
        }

        cout << best << '\n';
    }

    return 0;
}
