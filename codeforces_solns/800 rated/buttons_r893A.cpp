#include <bits/stdc++.h>
using namespace std;

int main() {

    // c is odd => the next player to get the turn when c becomes 0 is Katie
    // c is even => the next player to get the turn when c becomes 0 is Anna
    // so, the one with greater number of turns after c is 0 will win

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (c % 2 == 0) {
            // c even → compare a vs b normally
            if (a > b)
                cout << "First" << endl;
            else
                cout << "Second" << endl;
        }
        else {
            // c odd → comparison is reversed
            if (b > a)
                cout << "Second" << endl;
            else
                cout << "First" << endl;
        }
    }

    return 0;
}
