#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
Time: O(n^2)
Space: O(n) (for visited)
*/
int maxOperationsBrute(vector<int> nums, int k) {
    int n = nums.size();
    vector<bool> used(n, false);
    int ops = 0;

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        for (int j = i + 1; j < n; j++) {
            if (used[j]) continue;
            if (nums[i] + nums[j] == k) {
                used[i] = used[j] = true;
                ops++;
                break;
            }
        }
    }
    return ops;
}

/*
Approach 2 that came to mind: Sorting + Two Pointers
Time: O(n log n)
Space: O(1)
*/
int maxOperationsTwoPointers(vector<int> nums, int k) {
    sort(nums.begin(),
            nums.end()); // we need to sort, if we we'll use two pointers,
                        // otherwise we won't know for sure, whether to move
                        // left or right when sum is > k or < k

    int l = 0, r = nums.size() - 1;
    int ops = 0;

    while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == k) {
            l++;
            r--;
            ops++;
        }

        // if sum < k
        else if (sum < k)
            l++; // get the next smallest value

        else
            r--; // sum > k, then get the next largest value to check with
    }

    return ops;
}

/*
Approach 3: Hash Map 
Time: O(n)
Space: O(n)
*/
int maxOperationsHash(vector<int> nums, int k) {
    unordered_map<int, int> freq;
    int ops = 0;

    for (int x : nums) {
        int need = k - x;
        if (freq[need] > 0) {
            freq[need]--;
            ops++;
        } else {
            freq[x]++;
        }
    }
    return ops;
}

int main() {
    vector<pair<vector<int>, int>> tests = {
        {{1,2,3,4}, 5},
        {{3,1,3,4,3}, 6},
        {{2,2,2,2}, 4},
        {{1,1,1,1}, 5},
        {{1,2,3,3,4,5}, 6},
        {{4,2,3,1,3}, 6}
    };

    for (int i = 0; i < tests.size(); i++) {
        auto nums = tests[i].first;
        int k = tests[i].second;

        cout << "Test Case " << i + 1 << ":\n";
        cout << "nums = ";
        for (int x : nums) cout << x << " ";
        cout << ", k = " << k << "\n";

        cout << "Brute Force      : " << maxOperationsBrute(nums, k) << "\n";
        cout << "Two Pointers     : " << maxOperationsTwoPointers(nums, k) << "\n";
        cout << "Hash Map         : " << maxOperationsHash(nums, k) << "\n";
        cout << "-------------------------------\n";
    }

    return 0;
}
