// souvlaki and kalamaki are two players
// given a sequence of a -> n integers
// plays game of n-1 rounds
// 1st game: 1
// 2nd game: 2
// n-1th game : n-1

// souvlaki plays odd numbered rounds
// kalamaki plays even numbered rounds

// at each turn:
// either skip and proceed to next round or finish the round if the current was the last one
// swap a[i] and a[i+1]

// S fixes swap at (1, 3, 5, 7, 9 ...)
// K fixes swap at (2, 4, 6, 8 ....)
// so dangerous positions are (2,3), (4, 5), (6,7)
// round 2: K could swap (2, 3) and win the game
// round 4: K could swap (4,5) and win the game
// but it won't win only when values at (2,3) are equal (4, 5) are equal and so on
// and also can't win when a[2]== a[3] <= a[4]==a[5]

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n - 1; i += 2)
    {
        if (a[i] != a[i + 1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}