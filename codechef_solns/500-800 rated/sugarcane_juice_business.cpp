#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // 1 glass sugarcane -> 50 coins
    // 10 coins on sugarcane
    // 10 coins on salt and mint leaves
    // 15 coins on shop rent

    // profit -> 50 - (10 + 10 + 15) = 50 - 35 = 15

    // so when he sells one sugarcane -> 15 coins profit
    // when he sells N glasses -> 15 * N coins profit

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        cout << N * 15 << endl;
    }
}
