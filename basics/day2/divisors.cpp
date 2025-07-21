#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<int> divs;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            divs.push_back(i);
            if (n / i != i)
            {
                divs.push_back(n / i);
            }
        }
    }

    cout << "Divisors are: " << endl;
    for (auto i : divs)
    {
        cout << i << endl;
    }
}