#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    int t;
    cin >> t;
    while (t--)
    {
        int n, s = 0, l = 0;
        cin >> n;
        string contest;
        for (int i = 0; i < n; i++)
        {
            cin >> contest;
            if (contest == "START38")
                s++;
            else
                l++;
        }

        cout << s << " " << l << endl;
    }
}
