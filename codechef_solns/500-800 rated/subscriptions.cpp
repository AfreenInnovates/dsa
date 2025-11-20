#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int N, X;

        cin >> N >> X;

        int how_many_times = N / 6;

        if (N % 6 != 0)
        {
            how_many_times += 1;
        }

        cout << how_many_times * X << " ";
    }
}

// 1 % 6 = 1         || 1 / 6 = 0
// 12 % 6 = 0        || 12 / 6 = 2
// 16 % 6 = 4        || 16 / 6 = 2