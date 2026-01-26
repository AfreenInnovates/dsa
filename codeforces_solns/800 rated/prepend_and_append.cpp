// keep moving the pointers at the ends while they are different, because they must have come from the same operation. once they become same, stop. whatever the distance between them is the shortest string

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;//length of string
        
        string s;
        cin>>s;

        // two pointers are both ends of the string
        int l=0,r=n-1;

        while (l<r && s[l]!=s[r]) {
            l++;
            r--;
        }

        cout << max(0,r-l+1)<<endl;
    }
    return 0;
}