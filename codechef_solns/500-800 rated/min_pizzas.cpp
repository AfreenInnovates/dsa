#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // N - no. of friends
    // X - no. of slice for each friend
    // needed slices = X * N
    // needed pizzas = needed slices / 4
    // if needed slices % 4 != 0
    // needed pizzas += 1

    int T;
    cin >> T;

    while (T--)
    {
        int N, X;

        cin >> N >> X;

        int needed_slices = X * N;
        int needed_pizzas = needed_slices / 4;

        if (needed_slices % 4 != 0)
            needed_pizzas += 1;

        cout << needed_pizzas << endl;
    }
}
