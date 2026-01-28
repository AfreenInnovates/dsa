#include <bits/stdc++.h>
using namespace std;

int main() {
    int y;
    cin >> y;

    if (y % 400 == 0) {
        cout << "Yes";
    } else if (y % 100 == 0) {
        cout << "No";
    } else if (y % 4 == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
