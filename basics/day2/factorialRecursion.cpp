#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{

    if (n == 1 || n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    int n;
    cout << "Enter number to find factorial: ";
    cin >> n;

    int fact = factorial(n);
    cout << "Factorial of " << n << " = " << fact;
}