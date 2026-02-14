// An array is said to be beautiful if all its elements are equal.

// Given an array of integers, determine whether the array is beautiful or not.

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int>arr(n);

    for (int i=0;i<n; i++) cin >> arr[i];

    int x=arr[0];

    for (int i=1;i<n;i++) {
        if (arr[i]!=x) {
            cout << "NO"<<endl;
            exit(0);
        }
    }

    cout << "YES" << endl;

    return 0;
}