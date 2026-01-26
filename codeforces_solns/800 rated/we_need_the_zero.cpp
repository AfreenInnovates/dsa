// b1 xor b2 xor b3 ... xor bn
// = (a1 xor x) xor (a2 xor x) xor (a3 xor x) .... xor (an xor x) = a1 xor a2 xor a3 xor ... x xor x xor x
// if there are even number of terms (example 2):
    // (a1 xor x) xor (a2 xor x) = a1 xor x xor a2 xor x = a1 xor a2 xor (x xor x) = a1 xor a2 xor 0 = a1 xor a2
    // here we have no control of x, as it becomes 0, after we xor all x's. so if we get the xor of each number in the array to be 0, then 0 is the answer, otherwise there is no such answer.
// if odd number of terms (example 1):
    // a1 xor x = we'll be left with one x in this case
    // a1 xor x = 0 (must be)
    // so, a1 xor a1 = 0
    // so x must be equal to the xor of all elements in the arrayy
    // with 3 elements as example:
        // a1 xor a2 xor a3 xor x xor x xor x = a1 xor a2 xor a3 xor x (let's take a1 xor a2 xor a3 as Y)
        // Y xor x = 0
        // so x must be equal to Y, to get Y xor x = 0
        // so x = xor of all elements in the array

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; 
    cin >> t;
    while (t--)
    {
        long long n; 
        cin >> n;
        long long a[n]; 
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        long long total_xor = 0;
        for (int i = 0; i < n; i++) 
            total_xor ^= a[i];
        // XOR of all elements stored in total_xor

        if (n % 2 == 1)
        {
            cout << total_xor << endl; // if odd number of elements, total_xor (aka Y) is the x needed
        }
        else 
        {
            if (total_xor == 0) // if total_xor is 0 in even number of elements case, then good
                cout << total_xor << endl; 
            else
                cout << -1 << endl; // otherwise we can find no x
        }
    }
    return 0;
}