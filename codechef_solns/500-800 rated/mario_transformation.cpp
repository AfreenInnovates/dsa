#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // everytime he eats three -> back to normal
    // eats 1 -> huge
    // eats 2 -> small
    // eats 3 -> normal
    // eats 4 -> huge
    // eats 5 -> small
    // eats 6-> normal
    // so multiples of 3 -> normal
    // if remainder is 1 -> huge
    // if remainder is 2 -> small
    // if remainder is 0 -> normal

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (n % 3 == 0)
            cout << "normal" << endl;
        else if (n % 3 == 1)
            cout << "huge" << endl;
        else
            cout << "small" << endl;
    }
}
