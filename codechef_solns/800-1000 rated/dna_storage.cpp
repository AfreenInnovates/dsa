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
        // your code goes here

        string final_s = "";

        for (int i = 0; i < n; i += 2)
        {
            if (s[i] == '0' && s[i + 1] == '0')
                final_s += 'A';
            else if (s[i] == '0' && s[i + 1] == '1')
                final_s += 'T';
            else if (s[i] == '1' && s[i + 1] == '0')
                final_s += 'C';
            else
                final_s += 'G';
        }

        cout << final_s << endl;
    }
}
