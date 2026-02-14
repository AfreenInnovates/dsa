// #include <bits/stdc++.h>
// using namespace std;

// int main() {

//     int t;
//     cin >> t;

//     while (t--) {
//         long long n;
//         cin >> n;

//         long long maxi = 0;
//         long long cnt = 0;

//         for (long long i = 1; i <= n; i++) {
//             if (n % i == 0) {
//                 cnt++;
//                 maxi = max(maxi, cnt);
//             } else {
//                 cnt = 0;
//             }
//         }

//         cout << maxi << "\n";
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;

        long long i = 1;
        while(n % i == 0){
            i++;
        }

        cout << i-1 << "\n";
    }
}

