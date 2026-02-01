#include<bits/stdc++.h>
using namespace std;

void calcFactor(int n) {
    for (int i = n; i >= 1; i--) {
        if (n % i == 0)
            cout << i << " ";
    }
}

int main() {
    int n;
    cin >> n;
    calcFactor(n);
    return 0;
}
