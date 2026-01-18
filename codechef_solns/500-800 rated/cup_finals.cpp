#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while (t--) {
        int x,y,d;
        
        cin >> x>>y>>d;
        
        int diff = abs(x-y);
        if (diff <= d) cout << "yes" << endl;
        else cout << "no"<<endl;
    }
}
