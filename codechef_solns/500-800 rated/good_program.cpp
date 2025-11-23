#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // four bits - one nibble

    // the number of bits must be divisible by 4, for the program to be good

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (n % 4 == 0)
            cout << "good" << endl;
        else
            cout << "not good" << endl;
    }
}
