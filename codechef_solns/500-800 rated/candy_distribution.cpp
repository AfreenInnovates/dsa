#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // N candies
    // M friends
    // each to get equal number of even candies
    // if (N % M == 0 && (N / M) % 2 == 0)
    //     YES
    // else
    //     NO

    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;

        if (N % M == 0)
        {
            int per = N / M;
            if (per % 2 == 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}
