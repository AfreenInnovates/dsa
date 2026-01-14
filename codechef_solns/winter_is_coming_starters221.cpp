#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    
    // without jacket => temperature >= A
    // with jacket => temperature <= B
    // A <= B
    // only putting on jacket is counted as an action
    // temp < A => must wear, no remove
    // A <= T <= B => wearing jacket already, so no need to remov
    // T > B => must remove jacket
    
    int t;
    cin >> t;
    
    while (t--) {
        int N, A, B;
        cin >> N>>A>>B;
        
        int actions=0;
        bool wearing = false;
        
        vector<int> T(N);
        for (int i = 0; i <N;i++) cin >> T[i];
        
        for (int i = 0; i<N;i++) {
            if (T[i] < A) {
                if (!wearing) {
                    wearing = true;
                    actions++;
                }
            }
            else if (T[i] > B) {
                if (wearing) wearing=false;
            }
        }
        cout << actions << endl;
        
    }
    
    return 0;
}
