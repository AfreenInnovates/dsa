#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K, M;
        cin >> N >> K >> M;

        int capacity = K * M;
        int bags = (N + capacity - 1) / capacity;

        cout << bags << endl;
    }
}
