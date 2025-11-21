#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // N children -> each gets 1 candy
    // 1 packet -> 4 candies

    // chef has X candies
    // remaining children who need candies = N - X
    // if N-X == 0 then all children got candies, no need to purchase packets (0)

    // else we go to store and purchase
    // remaining children = N-X
    // 1 packet will give us 4 candies
    // if remaining children % 4 == 0 then we need remaining children / 4 number of packets
    // if % 4 != 0 then we need (remaining children / 4) + 1 number of packets

    // and if X>N, we won't need to purchase packets

    int T;
    cin >> T;
    while (T--)
    {
        int N, X;

        cin >> N >> X;

        if (X > N)
        {
            cout << 0 << endl;
            continue;
        }

        if (N - X == 0)
        {
            cout << 0 << endl;
            continue;
        }

        else
        {
            int remaining_children = N - X;
            if (remaining_children % 4 == 0)
                cout << remaining_children / 4 << endl;
            else
                cout << (remaining_children / 4) + 1 << endl;
        }
    }
}

// 2nd approach
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, X;
        cin >> N >> X;

        if (X >= N)
        {
            cout << 0 << "\n"; // Already enough candies
        }
        else
        {
            int remaining = N - X;
            int packets = (remaining + 3) / 4;
            cout << packets << "\n";
        }
    }
    return 0;
}
