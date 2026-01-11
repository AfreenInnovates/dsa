#include<bits/stdc++.h>
using namespace std;

// if the number 'n' is such that, if you subtract by 1 or add 1, it becomes divisble by 3 then Vanya wins
// otherwise Vova wins, because he'll try to bring the number back to what it was
// example: n = 3, 6, 9, ...
// vanya would do n-1 or n+1, then vova would do opposite of him, and it would keep going like that, and vova would win (as more than 10 moves would happen)
// example: n = 1, 2, 4, 5, ...
// then vanya can do n-1, or n+1, and win immediately

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;

        if (((n+1)%3) == 0 || ((n-1)%3) == 0) cout << "First"<<endl;
        else cout << "Second" << endl;
        
    }
}