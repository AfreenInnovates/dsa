#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    // 1 is not prime
    if (n <= 1)
        return false;

    // 2 is prime
    if (n == 2)
        return true;

    // even numbers > 2 are not prime
    if (n % 2 == 0)
        return false;

    // check odd divisors from 3 to sqrt(n)
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        if (isPrime(N))
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
