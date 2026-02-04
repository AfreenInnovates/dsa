#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        string s = "";  

        for (int i = 0; i < n; i++) {
            s = min(s + a[i], a[i] + s);
        }

        cout << s << "\n";
    }

    return 0;
}

/////////////////////
#include <bits/stdc++.h>
using namespace std;

// returns true if A is lexicographically smaller than B
bool isSmaller(const string &A, const string &B) {
    // A and B always have same length in this problem
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < B[i]) return true;
        if (A[i] > B[i]) return false;
    }
    // A == B
    return false;   // either is fine
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        string cur = "";  // starts empty

        for (int i = 0; i < n; i++) {
            string left  = a[i] + cur;
            string right = cur + a[i];

            if (isSmaller(left, right))
                cur = left;
            else
                cur = right;   // includes equal case
        }

        cout << cur << "\n";
    }

    return 0;
}
