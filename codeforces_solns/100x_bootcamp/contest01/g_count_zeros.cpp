#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N == 0) {
        cout << 1 << endl;
        return 0;
    }

    int count = 0;

    while (N > 0) {
        if (N % 10 == 0) {
            count++;
        }
        N /= 10;
    }

    cout << count << endl;
    return 0;
}
