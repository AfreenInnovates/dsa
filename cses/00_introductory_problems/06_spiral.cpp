#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long t;
    cin >> t;

    while (t--)
    {
        long long r, c;
        cin >> r >> c;

        // we can see that :
        // if row = col
        // the number would be row * col - (col - 1) -> (col * col) - (col - 1) = diagonal value

        long long d = max(r, c);
        long long diagonal_val = (d * d) - (d - 1);

        long long val;

        // case 1 : if r >= c
        // we are below or on the diagonal
        // movement depends on whether the row is even or odd
        // if row is odd :
        // value = diagonal_val - (r-c)
        // else :
        // value = diagonal_val + (r -c)

        if (r >= c)
        {
            if (r % 2 == 1)
                val = diagonal_val - (r - c);
            else
                val = diagonal_val + (r - c);
        }

        // if c > r:
        // we are above diagonal
        // column odd :
        // val = diagonal_val + (c - r)
        // else
        // val = diagonal_value - (c - r)

        else
        {
            if (c % 2 == 1)
                val = diagonal_val + (c - r);
            else
                val = diagonal_val - (c - r);
        }

        cout << val << "\n";
    }

    return 0;
}
