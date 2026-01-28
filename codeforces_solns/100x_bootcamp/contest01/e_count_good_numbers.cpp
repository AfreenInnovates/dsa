#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        if ((x != 0 && 18 % x == 0) || (x % 45 == 0)) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
