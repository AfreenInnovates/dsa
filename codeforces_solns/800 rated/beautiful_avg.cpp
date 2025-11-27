// We will track the maximum element in the array.
// Why? Because the maximum average subarray is always a subarray of length 1
// containing the maximum element
//
// Reason:
// - Adding other (smaller) elements will only reduce the average
// - avg(l, r) <= max(a[l..r])

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            maxi = max(x, maxi);
        }
        cout << maxi << "\n";
    }
}