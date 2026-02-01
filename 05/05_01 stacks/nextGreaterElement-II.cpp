#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//    approach 1: Brute Force 
//    Time: O(n^2)
vector<int> nextGreaterCircularBrute(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;

        while (j != i) {
            if (nums[j] > nums[i]) {
                ans[i] = nums[j];
                break;
            }
            j = (j + 1) % n;
        }
    }

    return ans;
}

// approach 2 : monotonic stack
// time : O(n)
vector<int> nextGreaterCircularStack(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;

    // Traverse twice from right to left
    for (int i = 2 * n - 1; i >= 0; i--) {
        int curr = nums[i % n];

        while (!st.empty() && st.top() <= curr) {
            st.pop();
        }

        if (i < n) {
            ans[i] = st.empty() ? -1 : st.top();
        }

        st.push(curr);
    }

    return ans;
}

void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 3};

    cout << "Input: ";
    printVector(nums);

    vector<int> brute = nextGreaterCircularBrute(nums);
    vector<int> stackAns = nextGreaterCircularStack(nums);

    cout << "Brute Force Result: ";
    printVector(brute);

    cout << "Stack Optimized Result: ";
    printVector(stackAns);

    return 0;
}
