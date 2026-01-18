#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int c=0, age;
        for (int i=0;i<n;i++) {
            cin >> age;
            if (age >= 10 && age <= 60) c++;
        }
        
        cout << c << endl;
        
    }
}
