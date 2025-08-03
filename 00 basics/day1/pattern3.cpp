#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // pattern 3
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4

    // i = 1, j = 1
    // 1

    // i = 2, j = 1
    // 1
    // i = 2, j = 2
    // 1 2

    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}