#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> cnt(26);
    for (char c : s)
        cnt[c - 'A']++;

    int odd = 0, mid = -1;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2)
        {
            odd++;
            mid = i;
        }
    }

    if (odd > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    string res;
    res.reserve(s.size());

    for (int i = 0; i < 26; i++)
        res += string(cnt[i] / 2, 'A' + i);

    if (mid != -1)
        res += char('A' + mid);

    for (int i = 25; i >= 0; i--)
        res += string(cnt[i] / 2, 'A' + i);

    cout << res;
}
