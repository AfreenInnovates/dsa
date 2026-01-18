#include <iostream>
using namespace std;

int main() {
    long long N, M;
    cin >> N;
    cin >> M;

    cout << N << " + " << M << " = " << (N + M) << "\n\n";
    cout << N << " - " << M << " = " << (N - M) << "\n\n";
    cout << N << " * " << M << " = " << (N * M) << "\n\n";
    cout << N << " / " << M << " = " << (N / M) << "\n\n";
    cout << N << " % " << M << " = " << (N % M) << "\n";

    return 0;
}
