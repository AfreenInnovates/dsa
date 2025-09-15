#include <bits/stdc++.h>
using namespace std;

void printFactors(int n, int i)
{
    if (i > 10)
        return;
    cout << n * i << endl;

    printFactors(n, i + 1);
}

int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    printFactors(n, 1);
    return 0;
}