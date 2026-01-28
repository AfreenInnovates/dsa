// at i=0, n-1, print n starts
// in the rows between, * [spaces] *
    // n-2 number of spaces

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    for (int i=0; i<n; i++) {
        if (i==0 || i==n-1) {
            for (int j=0;j<n;j++) cout << "*"; // print * n times, when i is 0 or n-1
        } else {
            // middle rows, print * then spaces then *
            cout << "*";
            for (int j=0;j<n-2;j++) cout << " ";
            cout << "*";
        }

        cout << endl;
    }
    return 0;
}