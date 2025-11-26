#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Input :
    // 5
    // Output :
    // 4 2 5 3 1

    // Input :
    // 3
    // Output:
    // NO SOLUTION

    // we can print the even numbers first and then the odd numbers
    // for numbers 2, 3 -> no solution

    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1;
        exit(0);
    }

    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION\n";
        exit(0);
    }

    for (int i = 2; i <= n; i += 2)
    {
        cout << i << " ";
    }

    for (int i = 1; i <= n; i += 2)
    {
        cout << i << " ";
    }

    return 0;
}