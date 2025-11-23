#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vector<int> A(3), B(3);
        cin >> A[0] >> A[1] >> A[2] >> B[0] >> B[1] >> B[2];

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int alice_score = A[1] + A[2];
        int bob_score = B[1] + B[2];

        if (alice_score > bob_score)
            cout << "Alice\n";
        else if (bob_score > alice_score)
            cout << "Bob\n";
        else
            cout << "Tie\n";
    }

    return 0;
}
