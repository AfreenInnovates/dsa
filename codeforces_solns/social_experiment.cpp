#include <bits/stdc++.h>
using namespace std;

int main() {

    // if less than or equal to 3, we can form teams with 2 or 3, and then the difference would not be applicable, it would be 2 or 3 itself
    // if greater, for example: if 4: 2 teams with each 2 can be formed, so difference = 0
    // the above can be done for any even number

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n <= 3)
            cout << n << '\n';
        else if (n % 2 == 0)
            cout << 0 << '\n';
        else
            cout << 1 << '\n';
    }
    return 0;
}
