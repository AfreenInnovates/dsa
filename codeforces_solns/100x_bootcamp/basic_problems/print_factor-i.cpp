#include<bits/stdc++.h>
using namespace std;

void calcFactor(int n) {
    for (int i = 1; i<=n/2; i++) {
        if (n % i == 0) cout << i << " ";
    }
    cout << n;
}

int main() {
    int n;
    cin>>n;
    
    calcFactor(n);
    
    return 0;
}