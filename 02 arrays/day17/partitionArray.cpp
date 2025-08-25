#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool partitionArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n % k != 0)
            return false;
        if (k == 0)
            return false;

        int numOfGroups = n / k;

        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;

        int fmax = 0;
        for (auto &p : freq)
            fmax = max(fmax, p.second);

        return fmax <= numOfGroups;
    }
};

int main()
{
    cout << boolalpha;
    Solution sol;

    vector<int> a{1, 2, 3, 4};
    cout << sol.partitionArray(a, 2) << "\n"; // true
    vector<int> b{3, 5, 2, 2};
    cout << sol.partitionArray(b, 2) << "\n"; // true
    vector<int> c{1, 5, 2, 3};
    cout << sol.partitionArray(c, 3) << "\n"; // false
    vector<int> d{1, 2, 2, 2, 4};
    cout << sol.partitionArray(d, 2) << "\n"; // false
    vector<int> e{2, 2, 1};
    cout << sol.partitionArray(e, 1) << "\n"; // true

    return 0;
}
