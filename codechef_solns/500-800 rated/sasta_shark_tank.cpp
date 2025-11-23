#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // valuation = offer / percentage_of_company

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int valuation_a = (a * 100) / 10;
        int valuation_b = (b * 100) / 20;

        if (valuation_a > valuation_b)
            cout << "first" << endl;
        else if (valuation_b == valuation_a)
            cout << "any" << endl;
        else
            cout << "second" << endl;
    }
}
