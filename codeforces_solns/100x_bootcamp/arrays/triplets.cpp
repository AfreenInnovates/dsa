// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int t;
//     cin>>t;

//     while (t--) {
//         int n;
//         cin >> n;

//         vector<long long> a(n);
//         for (int i = 0; i < n; i++) 
//             cin >> a[i];

//         long long X;
//         cin >> X;

//         long long ans=0;
//         set<tuple<int, int, int>> triplets;

//         for (int i=0; i<n;i++) {
//             for (int j=i+1; j<n;j++) {
//                 for (int k=j+1;k<n;k++) {
//                     if (a[i] +a[j]+a[k] == X) triplets.insert({i,j,k});
//                 }
//             }
//         }

//         cout << triplets.size() << endl;
//     }
// }

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

        long long X;
        cin >> X;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<long long, int> freq;

            for (int j = i + 1; j < n; j++) {
                long long sum = a[i] + a[j];
                long long find = X - sum;

                if (freq.count(find)) {
                    ans += freq[find];
                }

                // store a[j] for future k searches
                freq[a[j]]++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
