#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> ans;

        for (int i = 1; i <= (n / 2); i++)
        {
            ans.push_back(i);
            ans.push_back(-i);
        }

        if (n % 2 == 1)
        {
            ans.push_back(0);
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> testCases = {1, 2, 3, 4, 5};

    for (int n : testCases)
    {
        vector<int> res = sol.sumZero(n);

        cout << "Input n = " << n << " -> Output: ";
        for (int x : res)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
