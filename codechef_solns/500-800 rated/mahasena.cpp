#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int num_of_soldiers;
    cin >> num_of_soldiers;

    int count = 0;

    // loop through each soldier and get the input of no. of weapons each has
    // keep a count -> increment if even no. of weapons, and decrement otherwise
    // if count <= 0  == > not ready else ready

    for (int i = 0; i < num_of_soldiers; i++)
    {
        int num_of_weapons;

        cin >> num_of_weapons;

        if (num_of_weapons % 2 == 0)
            count++;
        else
            count--;
    }

    if (count <= 0)
        cout << "NOT READY\n";
    else
        cout << "READY FOR BATTLE\n";
}
