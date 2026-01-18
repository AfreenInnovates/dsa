#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    // X aircraft everyday
    // each aircraft -> 100 passengers
    
    int t;
    cin >> t;
    
    while (t--) {
        int x,n;
        cin >> x >> n;
        
        // x->number of aircrafts
        // n->number of passengers
        
        // 1 aircraft -> 100 passengers
        
        // how many passengers can x aircrafts take?
        int can_take = 100 * x;
        
        // how many passengers are left?
        int remaining_passengers = n - can_take;
        
        int more_aircrafts = 0;
        
        // for remaining_passengers how many more aircrafts needed?
        if (remaining_passengers > 0) {
            more_aircrafts = remaining_passengers / 100;
            if (remaining_passengers % 100 != 0)
                more_aircrafts++;
        }
        
        cout << more_aircrafts << endl;
    }
    
    return 0;
}

// OR

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int x, n;
        cin >> x >> n;

        int need = ceil(n / 100.0);
        cout << max(0, need - x) << '\n';
    }
    return 0;
}
