#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here

    // assets worth : 'A' billion dollars
    // wants to increase by 'X' billion dollars per year
    // goal : 'B' billion dollars
    // find how many years

    int T;
    cin >> T;

    while (T--)
    {
        int A, B, X;
        cin >> A >> B >> X;

        int c = 0;

        while (A < B)
        {
            A += X;
            c++;
        }

        cout << c << endl;
    }
}