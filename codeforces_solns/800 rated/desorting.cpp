// we care about changing the order at ith and i+1 th positions
// change the values of a[i] and a[i+1]
// because upto a[i], we add 1, so it remains in increasing order
// we subtract 1 from a[i+1] till a[n-1], so that order also remains the same
// it changes at a[i] and a[i+1]
// so the difference between a[i+1]-a[i], let's say is x
// in one operation, x reduces by 2 (we reduce the gap between a[i] and a[i+1] by 2)
// example: 1, 2, 3, 4, 5, 6
// let's pick 3, then:
// difference between 4 and 3 is 1, x=1
// in one operation, it'll become 1-2 = -1
// add 1 till 3, and subtract 1 from 4
// 2, 3, 4, 3, 4, 5
// now difference is 3-4 = -1
// how many operations?  = 1
// example 2: 1, 3, 5, 7, 9
// let's pick 3, then:
// difference between 5 and 3 = 2
// add 1 and subtract 1
// 2,4,4,6,8
// again add 1 and subtract 1:
// 3,5,3,5,7
// now unsorted, and difference = 3-5= -2
// number of operatios? = 2 

// so number of operations would be, (x/2) + 1

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // check if array is already not sorted
        bool sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                sorted = false;
                break;
            }
        }

        // If already not sorted, answer is 0
        if (!sorted) {
            cout << 0 << "\n";
            continue;
        }

        long long ans = LLONG_MAX;

        // find number of operations with every a[i] and a[i+1] (adjacent elements)
        // update with the one that would take minimum
        for (int i = 0; i < n - 1; i++) {
            long long x = a[i + 1] - a[i];

            // x >= 0 since array is sorted
            long long ops = (x / 2) + 1;

            ans = min(ans, ops);
        }

        cout << ans << "\n";
    }

    return 0;
}
