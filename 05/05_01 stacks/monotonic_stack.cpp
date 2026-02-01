#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Next Greater Element (to the right)
vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return ans;
}

// Next Smaller Element (to the right)
vector<int> nextSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return ans;
}

// Previous Greater Element (to the left)
vector<int> previousGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return ans;
}

// Previous Smaller Element (to the left)
vector<int> previousSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return ans;
}

// Helper function to print array
void printVector(vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};

    cout << "Array: ";
    printVector(arr);

    vector<int> nge = nextGreater(arr);
    vector<int> nse = nextSmaller(arr);
    vector<int> pge = previousGreater(arr);
    vector<int> pse = previousSmaller(arr);

    cout << "Next Greater:      ";
    printVector(nge);

    cout << "Next Smaller:      ";
    printVector(nse);

    cout << "Previous Greater:  ";
    printVector(pge);

    cout << "Previous Smaller:  ";
    printVector(pse);

    return 0;
}
