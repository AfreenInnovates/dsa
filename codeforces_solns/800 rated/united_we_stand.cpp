#include<bits/stdc++.h>
using namespace std;

// the maximum element always won't divide other elements

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i=0;i<n;i++) cin >> a[i];

        long long maxi = *max_element(a.begin(), a.end());

        vector<long long> b, c;

        for (int i=0;i<n;i++) {
            if (a[i] !=maxi) b.push_back(a[i]);
            else c.push_back(a[i]);
        }

        // if all elements got pushed to c (meaning all elements are same), then b is empty
        if (b.size() == 0) cout << -1 << endl;

        else {
            cout << b.size() << " " << c.size() << endl;
            for (auto num:b) cout << num << " ";
            cout << endl;

            for (auto num:c) cout << num << " ";
            cout << endl;
        }
    }
    return 0;
}