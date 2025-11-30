#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves;

void hanoi(int n, int from, int to, int aux)
{
    if (n == 0)
        return;

    hanoi(n - 1, from, aux, to);

    moves.push_back({from, to});

    hanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    cin >> n;

    hanoi(n, 1, 3, 2);

    cout << moves.size() << "\n";
    for (auto &p : moves)
        cout << p.first << " " << p.second << "\n";
}
