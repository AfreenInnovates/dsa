#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        if (i == 0 || i == N - 1 || M == 1) {
            // top row, bottom row, or single column
            for (int j = 0; j < M; j++) {
                cout << "^";
            }
        } else {
            // middle rows
            cout << "^";
            for (int j = 0; j < M - 2; j++) {
                cout << " ";
            }
            cout << "^";
        }
        cout << endl;
    }

    return 0;
}
