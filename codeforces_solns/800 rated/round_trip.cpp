#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long R, X, D;
        int n;
        cin >> R >> X >> D >> n;

        string s;
        cin >> s;

        int ratedRounds = 0;

        for (char c : s)
        {
            if (c == '1')
            {
                // div.1 → always rated
                ratedRounds++;

                if (R + D < X)
                {
                    R = R + D;
                }
                else
                {
                    R = X - 1;
                }
            }
            else
            { // c == '2'
                if (R < X)
                {
                    ratedRounds++;

                    if (R + D < X)
                    {
                        R = R + D;
                    }
                    else
                    {
                        R = X - 1;
                    }
                }
                else
                {
                    // div.2 and R >= X → NOT RATED
                    // rating does not change
                }
            }
        }

        cout << ratedRounds << "\n";
    }

    return 0;
}
