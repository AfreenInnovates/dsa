#include<bits/stdc++.h>
using namespace std;

int main() {
    // the sub segment can also be the number itself, or the range in which it is most common
    // so if the number exists -> yes
    // if does not exist -> no (cause then there would be no sub segment where it is most common)

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n);
        bool found = false;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == k) found = true;
        }

        cout << (found ? "YES\n" : "NO\n");
    }
    return 0;
}