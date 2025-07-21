#include <bits/stdc++.h>
using namespace std;

int sum_n(int n)
{
    if (n == 0)
        return 0;

    return n + sum_n(n - 1);
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << endl;
    int sum = sum_n(n);

    cout << sum;
}