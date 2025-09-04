#include <bits/stdc++.h>
using namespace std;

// -------------------- Approach 1: Brute Force (extra array) --------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
int removeElement_app1(vector<int> &nums, int val)
{
    vector<int> new_array;
    for (auto num : nums)
    {
        if (num != val)
        {
            new_array.push_back(num);
        }
    }

    for (int i = 0; i < new_array.size(); i++)
    {
        nums[i] = new_array[i];
    }

    return new_array.size();
}

// -------------------- Approach 2: Swap with End --------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
int removeElement_app2(vector<int> &nums, int val)
{
    int end = nums.size() - 1;
    int i = 0;

    while (i <= end)
    {
        if (nums[i] == val)
        {
            swap(nums[i], nums[end]);
            end--; // shrink range
        }
        else
        {
            i++; // only move if current element is good
        }
    }

    return end + 1;
}

// -------------------- Approach 3: Shift Left --------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
int removeElement_app3(vector<int> &nums, int val)
{
    int j = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
    }

    return j;
}

int main()
{
    vector<int> nums1 = {1, 2, 4, 6, 6, 8};
    vector<int> nums2 = nums1;
    vector<int> nums3 = nums1;

    int val = 6;

    cout << "Original array: ";
    for (int x : nums1)
        cout << x << " ";
    cout << "\n\n";

    int k1 = removeElement_app1(nums1, val);
    cout << "Approach 1 (extra array): k = " << k1 << ", nums = ";
    for (int i = 0; i < k1; i++)
        cout << nums1[i] << " ";
    cout << "\n";

    int k2 = removeElement_app2(nums2, val);
    cout << "Approach 2 (swap with end): k = " << k2 << ", nums = ";
    for (int i = 0; i < k2; i++)
        cout << nums2[i] << " ";
    cout << "\n";

    int k3 = removeElement_app3(nums3, val);
    cout << "Approach 3 (shift left): k = " << k3 << ", nums = ";
    for (int i = 0; i < k3; i++)
        cout << nums3[i] << " ";
    cout << "\n";

    return 0;
}
