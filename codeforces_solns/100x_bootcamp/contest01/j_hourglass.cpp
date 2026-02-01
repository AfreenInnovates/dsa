// upper half:
// number of spaces = i
// number of dots = n-i

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // upper half
    for (int i = 0; i<n;i++) {
        int spaces=i;
        int dots=n-i;

        for (int space=0;space<spaces;space++) cout << " ";

        // for (int dot = 0; dot<dots; dot++) cout << ". "; -> wrong
        
        for (int dot=0; dot<dots; dot++) {
            if (dot == dots-1) cout<<".";   // last dot must not have space
            else cout << ". ";
        }

        cout << endl;
    }

    // lower half
    for (int i=n-2; i>=0; i--) {
        int spaces = i;
        int dots = n - i;

        for (int space=0;space<spaces;space++) cout << " ";
        // for (int dot = 0; dot<dots; dot++) cout << ". "; -> wrong

        for (int dot=0; dot<dots; dot++) {
            if (dot == dots-1) cout<<".";   
            else cout << ". ";
        }

        cout << endl;
    }

    return 0;
}