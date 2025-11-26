#include <bits/stdc++.h>
using namespace std;

int printSeq(long long n)
{
    cout << n << " ";

    if (n == 1)
        return 1;

    if (n % 2 == 0)
        return printSeq(n / 2);
    else
        return printSeq(n * 3 + 1);
}

int main()
{
    long long n;
    cin >> n;
    printSeq(n);
    return 0;
}
