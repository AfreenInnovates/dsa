#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // pattern 5
    // * * * *
    // * * *
    // * *
    // *

    // i = 4, j = 1
    // * * * *

    // i = 3, j = 1
    // * * *

    // print * upto i times: run j upto i times

    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}