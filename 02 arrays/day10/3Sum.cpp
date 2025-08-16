#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSumHashset(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        unordered_set<int> hashset;

        for (int j = i + 1; j < n; j++)
        {
            int needed = -(nums[i] + nums[j]);

            if (hashset.find(needed) != hashset.end())
            {
                vector<int> temp = {nums[i], nums[j], needed};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashset.insert(nums[j]);
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

vector<vector<int>> threeSumTwoPointer(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    cout << "Approach 1 (Hashset):\n";
    for (auto &triplet : threeSumHashset(nums))
    {
        for (int val : triplet)
            cout << val << " ";
        cout << "\n";
    }

    cout << "\nApproach 2 (Two Pointer):\n";
    for (auto &triplet : threeSumTwoPointer(nums))
    {
        for (int val : triplet)
            cout << val << " ";
        cout << "\n";
    }
}
