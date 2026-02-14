// You are given an array of integers.

// Your task is to print all elements that occur exactly once in the array, in the same order as they appear in the input.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> freq;

    for (int x : arr)
        freq[x]++;

    for (int x : arr) {
        if (freq[x] == 1)
            cout << x << " ";
    }

    return 0;
}
