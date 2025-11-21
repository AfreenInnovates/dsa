#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {

        long long X, Y;
        cin >> X >> Y;

        // Approach 1 :  loop method
        // keep increasing months until renting cost >= purchase cost
        // total renting cost = X * i
        // when total_renting >= Y, stop and answer = i-1

        long long ans_loop = 0;

        for (long long i = 1;; i++)
        {
            long long total_renting = X * i;

            if (total_renting >= Y)
            {
                ans_loop = i - 1;
                break;
            }
        }

        // Approach 2 : Mathematical formula
        // X * m < Y
        // m < Y/X
        // max m = floor((Y - 1) / X)

        long long ans_math = (Y - 1) / X;

        cout << ans_loop << " " << ans_math << "\n";
    }

    return 0;
}
