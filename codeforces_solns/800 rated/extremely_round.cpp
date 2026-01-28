// so 1-> 9, there are 9 numbers which would be classified as extremely round, as all have one non zero digit only
// after that it'll be the multiples of 10, like 10, 20, 30, 40
// so for 42 => there are 13 extremely round numbers between 1 to 42 => 1 to 9 (9 nos.) + 10 + 20 + 30 + 40 = 9 + 4 = 13 nos.

#include <bits/stdc++.h>
using namespace std;

bool isExtremelyRound(int x) {
    int nonZero = 0;
    while (x > 0) {
        if (x % 10 != 0) nonZero++;
        x /= 10;
    }
    return nonZero == 1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int count = 0;

        for (int d = 1; d <= 9; d++) {
            long long x = d;
            while (x <= n) {
                if (isExtremelyRound(x)) {   
                    count++;
                }
                x *= 10;
            }
        }

        cout << count << '\n';
    }

    return 0;
}
