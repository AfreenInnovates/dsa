#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n = 5, i, j;
    
    for (i = n; i>=1; i--) {
        for (j=1; j<=i;j++) {
            cout << '*';
        }
        cout << "\n";
    }
    
    return 0;
}