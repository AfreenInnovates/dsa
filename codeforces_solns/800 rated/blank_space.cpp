#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >>n;

        int maxiL =0, zeros=0;

        for (int i=0;i<n;i++) {
            int x;
            cin >> x;

            if (x==0) {
                zeros++;
                maxiL=max(maxiL, zeros); // increase the maxiL only when there's 0s
            } else zeros=0; // else make zeros back to 0, and continue comparing
        }

        cout << maxiL << endl;
    }    

    return 0;
}
