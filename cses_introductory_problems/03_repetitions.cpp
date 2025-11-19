#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int l = 0, r = 1;
    int maxL = 1;

    while (r < s.size())
    {
        if (s[l] == s[r])
        {
            maxL = max(maxL, r - l + 1);
            r++;
        }
        else
        {
            while (l < r)
                l++;

            // r++;
        }
    }

    cout << maxL;
    return 0;
}
