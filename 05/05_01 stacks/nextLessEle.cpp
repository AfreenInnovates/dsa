#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    int arr[] = {3, 7, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> nextLess(n);

    for (int i = n - 1; i >= 0; i--) {
        cout << "\nProcessing " << arr[i] << "\n";

        while (!st.empty() && st.top() >= arr[i]) {
            cout << "  pop " << st.top()
                 << " (>= " << arr[i] << ")\n";
            st.pop();
        }

        if (st.empty()) {
            nextLess[i] = -1;
            cout << "  next less = none\n";
        } else {
            nextLess[i] = st.top();
            cout << "  next less = " << st.top() << "\n";
        }

        cout << "  push " << arr[i] << "\n";
        st.push(arr[i]);
    }

    cout << "\nNext less values: ";
    for (int x : nextLess) cout << x << " ";
    cout << "\n";

    return 0;
}
