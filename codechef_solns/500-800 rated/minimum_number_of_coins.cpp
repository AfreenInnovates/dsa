#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

    int t, coins=0;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        // if number not visible by 5 or 10 => not possible so -1
        if (n % 5 != 0) cout << -1 << endl;
        
        else {
            coins = n/10;
            
            // if still 5 rupees is pending
            if (n%10==5) coins++;
            cout << coins << endl;
        }
        
    }
    
    return 0;
}
