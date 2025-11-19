#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;

    cin >> s;

    int ans = 1, c = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            c++;
        else
            c = 1;

        ans = max(ans, c);
    }

    cout << ans;

    return 0;
}