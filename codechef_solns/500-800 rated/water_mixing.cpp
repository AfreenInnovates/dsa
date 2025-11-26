#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here

    // X litres hot 
    // Y litres cold 
    // initial temperature -> A 
    // A + 1 => 1 litre of hot 
    // A - 1 => 1 litre of cold 

    // to check if we can set temperature B 


    int t;
    cin >> t;
    while (t--) {
        int A, B, X, Y;
        cin >> A >> B >> X >> Y;

        int need = B - A;

        if (need > 0) {
            // need hot water
            if (X >= need) cout << "YES\n";
            else cout << "NO\n";
        } else if (need < 0) {
            // need cold water
            if (Y >= abs(need)) cout << "YES\n";
            else cout << "NO\n";
        } else {
            // need == 0
            cout << "YES\n";
        }
    }
}