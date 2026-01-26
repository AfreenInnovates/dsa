#include <bits/stdc++.h>
using namespace std;

/*
examples:

example 1:
n = 3
a = [15, 35, 21]

all pairs:
gcd(15,35) = 5
gcd(15,21) = 3
gcd(35,21) = 7

no pair has gcd <= 2
so we cannot form a good prefix of length 2
answer: no


example 2:
n = 4
a = [35, 10, 35, 14]

pair (10,14):
gcd(10,14) = 2 <= 2

we can reorder as:
[10, 14, 35, 35]

prefix gcds:
gcd(10,14) = 2
gcd(10,14,35) = 1
gcd(10,14,35,35) = 1

all prefixes are good
answer: yes


example 3:
n = 3
a = [6, 9, 3]

all gcds are 3
no gcd <= 2
answer: no


example 4:
a = [5, 10, 15, 2]
we look for any pair with gcd <= 2.
gcd(10, 2) = 2  -> valid starting pair
start array as:
[2, 10, ?, ?]
prefix length 2:
gcd(2,10) = 2 <= 2  -> good
add 5:
gcd(2,10,5)
= gcd(gcd(2,10),5)
= gcd(2,5)
= 1 <= 3  -> good
add 15:
gcd(2,10,5,15)
= gcd(1,15)
= 1 <= 4  -> good
final beautiful ordering:
[2, 10, 5, 15]
*/

int main() {
    int t;
    cin >> t;  

    while (t--) {
        int n;
        cin >> n;  

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];   
        }

        bool possible = false;

        // we try all pairs 
        // only the first prefix of length 2 matters
        for (int i = 0; i < n && !possible; i++) {
            for (int j = i + 1; j < n; j++) {

                // if gcd of any pair is <= 2,
                // we can place that pair first
                if (__gcd(a[i], a[j]) <= 2) {
                    possible = true;
                    break;
                }
            }
        }

        if (possible)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
