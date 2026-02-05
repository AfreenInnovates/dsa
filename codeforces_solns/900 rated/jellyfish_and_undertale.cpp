/*

1) Each tool i increases the timer by x[i],
   but because of the cutoff, timer can never exceed 'a'.

2) The BEST moment to use a tool is when the timer is low,
   so that its increase is not wasted by the cutoff.

3) a tool with value x[i] can contribute at most
   (a - 1) extra seconds of survival:
      - Because even if x[i] is huge,
        we can only raise timer up to 'a',
        and after that it immediately decreases by 1.

4) Therefore, the real useful contribution of tool i is:
      min(x[i], a - 1)

5) The initial timer already gives us 'b' seconds.

So the maximum total time is simply:

    b + sum over all tools of min(x[i], a - 1)

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;  

    while (t--)
    {
        long long a, b, n;
        cin >> a >> b >> n;

        vector<long long> x(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];

        long long maximum_time = b;

        for (int i = 0; i < n; i++)
            maximum_time += min(x[i], a - 1);

        cout << maximum_time << endl;
    }

    return 0;
}
