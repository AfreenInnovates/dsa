#include <bits/stdc++.h>
using namespace std;

void print(int i, int n)
{
    if (i >= 1)
    {
        cout << i << endl;
    }

    else
    {
        return;
    }

    print(i - 1, n);
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    int i = n;

    print(i, n);
}