#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // pattern 1
    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1

    // i = 5, j = 1
    // run j upto i

    // i = 4, j = 1
    // run j upto i times

    int n;
    cout << "Enter n: ";
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        cout << endl;
    }
}