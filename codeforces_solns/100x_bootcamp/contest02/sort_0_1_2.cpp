#include <bits/stdc++.h>
using namespace std;

int main() {
 int n;
    cin >> n;

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 0) cnt0++;
        else if(x == 1) cnt1++;
        else cnt2++;
    }

    // in descending order: 2 -> 1 -> 0
    while(cnt2--) cout << 2 << " ";
    while(cnt1--) cout << 1 << " ";
    while(cnt0--) cout << 0 << " ";

    return 0;
}
