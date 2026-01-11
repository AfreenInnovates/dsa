#include<bits/stdc++.h>
using namespace std;

int main() {
    // whenever there are three dots: . . . 
    // we can fill first and third, and then the middle one fills
    // middle will always fill no matter what because its given if i-1, and i+1 is filled, i will fill
    // so we can use operation 2, and take water from i th to other empty cells and fill 
    // so whenever there is three dots, we only need to do twice of first operation
    // if we don't find any three dots consecutively, we'll return the number of empty cells

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool three_dots_consecutively=false;
        int count_empty=0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '.' && i + 1< n && s[i+1] == '.' && i + 2 < n && s[i+2] == '.') {
                three_dots_consecutively = true;
                break;
            } 
            // otherwise count no. of empty cells
            if (s[i] == '.') count_empty++;
        }

        if (three_dots_consecutively) cout << 2 << endl;
        else cout << count_empty<<endl;
    }
}