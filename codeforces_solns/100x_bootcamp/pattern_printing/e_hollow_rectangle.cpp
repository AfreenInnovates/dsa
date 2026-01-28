
#include<bits/stdc++.h>
using namespace std;

int main() {
    int m,n;
    cin>>m>>n;

    for (int i=0; i<m; i++) {
        if (i==0 || i==m-1) {
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