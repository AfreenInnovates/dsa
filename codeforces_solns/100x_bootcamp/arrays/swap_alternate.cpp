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

        for (int i = 0; i + 1 < n; i += 2) {
            long long temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;

            // OR:
            // swap(a[i], a[i+1]);
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
