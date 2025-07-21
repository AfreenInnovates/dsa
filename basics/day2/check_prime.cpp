#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i != i)
            {
                count += 2;
            }
            else
                count += 1;
        }
    }

    if (count > 2)
    {
        cout << "Not prime";
    }
    else
    {
        cout << "Prime";
    }
}