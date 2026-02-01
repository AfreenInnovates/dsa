#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // upper half (including middle)
    for (int i = 0; i < n; i++) {
        // leading spaces
        for (int s = 0; s < i; s++)
            cout << " ";

        cout << ">";

        // inner spaces + right >
        if (i > 0) {
            for (int s = 0; s < 2*i - 1; s++)
                cout << " ";
            cout << ">";
        }

        cout << "\n";
    }

    // lower half
    for (int i = n - 2; i >= 0; i--) {
        for (int s = 0; s < i; s++)
            cout << " ";

        cout << ">";

        if (i > 0) {
            for (int s = 0; s < 2*i - 1; s++)
                cout << " ";
            cout << ">";
        }

        cout << "\n";
    }

    return 0;
}
