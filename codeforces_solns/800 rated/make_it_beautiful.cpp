#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while (t--) {
        int n;
        cin>>n;

        long long a[n];
        for (int i=0; i<n;i++) cin >> a[i];

        sort(a,a+n);

        long long maxi = a[n-1];
        long long mini = a[0];

        // if maxi==mini, then all elements are same, and not possible to make array beautiful
        if (maxi == mini) {
            cout << "no"<<endl;
        }

        else {
            cout << "yes"<<endl;
            cout << maxi<< " ";
            for (int i =0; i<n-1; i++) cout << a[i] << " "; // print rest of array elements, from min to n-2th position
            cout << endl;
        }
    }

    return 0;
}