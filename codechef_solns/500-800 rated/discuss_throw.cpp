#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here

    int t;
    cin >> t;
    while (t--)
    {
        int d1, d2, d3;
        cin >> d1 >> d2 >> d3;

        int maxi;
        if (d1 > d2)
        {
            if (d1 > d3)
                maxi = d1;
            else
                maxi = d3;
        }
        else
        {
            if (d2 > d3)
                maxi = d2;
            else
                maxi = d3;
        }

        cout << maxi << endl;
    }
}