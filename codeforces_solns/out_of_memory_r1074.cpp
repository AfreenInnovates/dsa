#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long h;
        cin >> n >> m >> h;

        vector<long long> original(n), current(n);
        vector<int> last(n, -1);

        for (int i = 0; i < n; i++) {
            cin >> original[i];
        }

        int reset = 0;

        while (m--) {
            int b;
            long long c;
            cin >> b >> c;
            b--;  

            // if this index wasn't updated since last reset, restore originalinal
            if (last[b] != reset) {
                current[b] = original[b];
            }

            current[b] += c;
            last[b] = reset;

            if (current[b] > h) {
                reset++;  
            }
        }

        for (int i = 0; i < n; i++) {
            if (last[i] == reset) {
                cout << current[i];
            } else {
                cout << original[i];
            }
            cout << (i + 1 < n ? ' ' : '\n');
        }
    }

    return 0;
}
