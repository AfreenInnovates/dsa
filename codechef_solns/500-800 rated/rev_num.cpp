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

        int rev = 0;
        while (N > 0)
        {
            int digit = N % 10;
            rev = rev * 10 + digit;
            N /= 10;
        }

        cout << rev << "\n";
    }
}