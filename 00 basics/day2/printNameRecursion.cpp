#include <bits/stdc++.h>
using namespace std;

void printName(string name, int i, int n)
{
    if (i == n + 1) // or `(i > n)`
    {
        return;
    }
    else
    {
        cout << name << endl;
    }

    printName(name, i + 1, n);
}

int main()
{
    int n;
    string name = "Afreen";
    cout << "Enter number of times to print: ";
    cin >> n;

    int i = 1;

    printName(name, i, n);
}
