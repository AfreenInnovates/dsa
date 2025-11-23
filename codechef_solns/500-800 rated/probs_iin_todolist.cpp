#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        int rem = 0;

        for (int i = 0; i < N; i++)
        {
            int d;
            cin >> d;
            if (d >= 1000)
                rem++;
        }

        cout << rem << endl;
    }
}