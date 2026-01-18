#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long mn, mx;

    if (a <= b && a <= c) {
        mn = a;
    } else if (b <= a && b <= c) {
        mn = b;
    } else {
        mn = c;
    }

    if (a >= b && a >= c) {
        mx = a;
    } else if (b >= a && b >= c) {
        mx = b;
    } else {
        mx = c;
    }

    cout << "Min = " << mn << endl;
    cout << "Max = " << mx << endl;

    return 0;
}
