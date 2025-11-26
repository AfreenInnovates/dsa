#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long result = 0;
    while (n > 0)
    {
        n /= 5;
        result += n;
    }

    cout << result << "\n";
    return 0;
}
