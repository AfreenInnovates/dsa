#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    int T;
    cin >> T;

    while (T--)
    {
        int A, B, C;

        cin >> A >> B >> C;

        int lowest = max(A, C);
        int highest = B;

        if (lowest <= highest)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
