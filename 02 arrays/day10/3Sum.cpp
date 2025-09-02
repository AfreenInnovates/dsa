#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute-force O(n^3)
vector<vector<int>> threeSumBruteForce(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
}

// Approach 2: Hashset O(n^2)
vector<vector<int>> threeSumHashset(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        unordered_set<int> hashset; // empties everytime we move to next ith element
        for (int j = i + 1; j < n; j++)
        {
            int needed = -(nums[j] + nums[i]);

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

// Approach 3: Two Pointer O(n^2)
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

void printTriplets(const vector<vector<int>> &triplets)
{
    for (auto &t : triplets)
    {
        for (int val : t)
            cout << val << " ";
        cout << "\n";
    }
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    cout << "Approach 1 (Brute-force):\n";
    printTriplets(threeSumBruteForce(nums));

    cout << "\nApproach 2 (Hashset):\n";
    printTriplets(threeSumHashset(nums));

    cout << "\nApproach 3 (Two Pointer):\n";
    printTriplets(threeSumTwoPointer(nums));

    return 0;
}
