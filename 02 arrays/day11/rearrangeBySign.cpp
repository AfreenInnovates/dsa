#include <bits/stdc++.h>
using namespace std;

// Approach 1: Split positives and negatives, then merge
// Time: O(N) + O(N/2) ≈ O(N)
// Space: O(N)
void approach1(vector<int> &arr)
{
    int n = arr.size();

    vector<int> pos, neg;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            neg.push_back(arr[i]);
        else
            pos.push_back(arr[i]);
    }

    for (int i = 0; i < n / 2; i++)
    {
        arr[i * 2] = pos[i];
        arr[i * 2 + 1] = neg[i];
    }
}

// Approach 2: Place positives at even indices and negatives at odd indices
// Time: O(N)
// Space: O(N)
vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    int neg = 1, pos = 0;
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            ans[pos] = nums[i];
            pos += 2;
        }
        else
        {
            ans[neg] = nums[i];
            neg += 2;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};

    cout << "Original array:\n";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    vector<int> arr1 = arr;
    approach1(arr1);
    cout << "\nRearranged array (Approach 1 - split & merge):\n";
    for (int x : arr1)
        cout << x << " ";
    cout << "\n";

    vector<int> arr2 = rearrangeArray(arr);
    cout << "\nRearranged array (Approach 2 - even/odd placement):\n";
    for (int x : arr2)
        cout << x << " ";
    cout << "\n";

    return 0;
}
