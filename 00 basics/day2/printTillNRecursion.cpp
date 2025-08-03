#include <bits/stdc++.h>
using namespace std;

void print(int i, int n)
{
    if (i < n + 1)
    {
        cout << i << endl;
    }

    else
    {
        return;
    }

    print(i + 1, n);
}

int main()
{
    int n;
    cout << "Enter till which number: ";
    cin >> n;

    int i = 1;

    print(i, n);
}