#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // pattern 2
    // *
    // * *
    // * * *
    // * * * *

    // when i = 1, j = 1
    // *

    // i = 2, j = 1
    // *
    // i = 2, j = 2
    // * *

    // i = 3, j = 1
    // *
    // i = 3, j = 2
    // * *
    // i = 3, j = 3
    // * * *

    int n;
    cout << "Enter n: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}