#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // pattern 4
    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4

    // i = 1, j = 1
    // 1

    // i = 2, j = 1, j = 2
    // 2 2

    // i = 3, j = 1, 2, 3
    // 3 3 3

    // print i, for i times

    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}