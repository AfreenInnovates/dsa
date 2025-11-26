#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        string ans = "";
        for (char c : s)
        {
            if (c == 'A')
                ans += 'T';
            else if (c == 'T')
                ans += 'A';
            else if (c == 'C')
                ans += 'G';
            else
                ans += 'C'; // c == 'G'
        }

        cout << ans << endl;
    }
}
