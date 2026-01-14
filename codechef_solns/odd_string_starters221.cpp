#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    // string S, length N, only lowercase letters
    // Si = Sj, and i<j, and j-i %2 != 0
    // characters cannot be in 0, 2, 4, 6 .. positions
    // so they must be one on even and one on odd index
    // 
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        vector<int> freq(26,0);
        for (char c : s) freq[c-'a']++;
        
        bool ok =true;
        
        for (int f : freq) {
            if (f > 2) {
                ok=false;
                break;
            }   
        }
        
        cout << (ok ? "yes\n":"no\n");
        
    }
}
