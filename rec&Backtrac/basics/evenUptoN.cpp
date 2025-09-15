#include <bits/stdc++.h>
using namespace std;

void printEven(int n, int i)
{
    if (i > n) // or i >= n, if don't want to include n (if n is even)
        return;

    if (i % 2 == 0)
    {
        cout << i << " ";
    }
    printEven(n, i + 1);
}

int main()
{
    int n;
    cout << "Enter till which number to print even: " << endl;
    cin >> n;
    printEven(n, 1);
    return 0;
}