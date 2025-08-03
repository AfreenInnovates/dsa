#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // pattern7
    //     *
    //   * * *
    // * * * * *

    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }

        for (int j = 1; j <= ((2 * i) - 1); j++)
        {
            cout << "*";
        }

        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }

        cout << endl;
    }
}