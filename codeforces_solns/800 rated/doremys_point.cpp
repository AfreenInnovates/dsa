#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    // so b1 + b2 = b2 + b3 = ...
    // cancelling b2 on both sides, b1=b3
    // so alternate numbers must be same (so in total, there would be just 2 unique numbers) 
    // if there are even numbers in the array, then there must be two unique numbers -> yes possible
    // if there are odd numbers array, the frequency of one element should be just one more than the other (assuming 2 unique elements) -> yes possible
    // greater than 3 or more => not possible

    while (t--) {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        map<long long, long long> mpp;
        for (int i = 0; i < n; i++) mpp[a[i]]++;

        if (mpp.size() >= 3) cout << "No"<<endl;

        else {
            long long f1 = mpp.begin()->second;
            long long f2 = mpp.rbegin()->second;

            if (f1 == f2) cout << "Yes" << endl;
            else if (n%2 == 1 && abs(f1-f2)==1) cout << "Yes"<<endl;
            else cout << "No"<<endl;
        }
    }
    return 0;
}