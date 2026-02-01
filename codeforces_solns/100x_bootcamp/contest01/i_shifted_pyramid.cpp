// we can see that the number of spaces is same as the ith value (i starting from 0)
// and number of x is i+1

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    for (int i =0; i<n; i++) {
        for (int j =0; j<i;j++) cout << " ";
        for (int k=0;k<i+1;k++) cout << "x";

        cout << endl;
    }

    return 0;
}