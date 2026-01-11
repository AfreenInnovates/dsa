#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {3, 7, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> prevLessIdx(n);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        cout << "\nProcessing arr[" << i << "] = " << arr[i] << "\n";

        while (!st.empty() && arr[st.top()] > arr[i]) {
            cout << "  pop index " << st.top()
                 << " (value " << arr[st.top()] << ")\n";
            st.pop();
        }

        if (st.empty()) {
            prevLessIdx[i] = -1;
            cout << "  previous less = none\n";
        } else {
            prevLessIdx[i] = st.top();
            cout << "  previous less index = " << st.top()
                 << " (value " << arr[st.top()] << ")\n";
        }

        cout << "  push index " << i << "\n";
        st.push(i);
    }

    cout << "\nPrevious less indices:\n";
    for (int i = 0; i < n; i++) {
        cout << prevLessIdx[i] << " ";
    }
    cout << "\n";

    return 0;
}
