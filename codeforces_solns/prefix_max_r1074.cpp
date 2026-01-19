#include <bits/stdc++.h>
using namespace std;

// long long value(const vector<int>& a) {
//     long long sum = 0;
//     int maxi = 0;
//     for (int x : a) {
//         maxi = max(maxi, x);
//         sum += maxi;
//     }
//     return sum;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//         }

//         long long ans = value(a);  

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 swap(a[i], a[j]);
//                 ans = max(ans, value(a));
//                 swap(a[i], a[j]); 
//             }
//         }

//         cout << ans << endl;;
//     }
//     return 0;
// }

// array with n elements
// we can find the max element, and get it in the start (so swap with the a1)
// and then that max element would be max in every prefix of the array
// number of prefixes : length n (size of array)
// so the answer would simply be : max(a) * n
// the max element would be max in every prefix, so multiple the max element to the number of prefixes = max(a) * n

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int maxi = *max_element(a.begin(), a.end());

        long long ans = maxi*n;

        cout << ans << endl;;
    }
    return 0;
}