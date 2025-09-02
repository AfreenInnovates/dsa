#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Merge using extra array
-----------------------------------
- Time Complexity: O(m + n)   // Linear scan through both arrays once
- Space Complexity: O(m + n)  // Extra array used to hold merged elements
*/
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> merged(m + n);
    int i = 0, j = 0, index = 0;

    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
            merged[index++] = nums1[i++];
        else
            merged[index++] = nums2[j++];
    }

    while (i < m)
        merged[index++] = nums1[i++];

    while (j < n)
        merged[index++] = nums2[j++];

    for (int k = 0; k < m + n; k++)
        nums1[k] = merged[k];
}

/*
Approach 2: In-place merge using swap + sorting
-----------------------------------------------
- Time Complexity: O((m + n) log(m + n))
  (Because after swapping, both arrays are sorted separately)
- Space Complexity: O(1)
*/
void mergeInPlace(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int left = m - 1, right = 0;

    while (left >= 0 && right < n)
    {
        if (nums1[left] > nums2[right])
            swap(nums1[left], nums2[right]);
        left--;
        right++;
    }

    // Sort both arrays
    sort(nums1.begin(), nums1.begin() + m);
    sort(nums2.begin(), nums2.end());

    for (int i = 0; i < n; i++)
        nums1[m + i] = nums2[i];
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    int m = 3, n = 3;

    vector<int> nums1_copy1 = {1, 3, 5, 0, 0, 0};
    merge(nums1_copy1, m, nums2, n);
    cout << "After Approach 1 (Extra Array): ";
    for (int x : nums1_copy1)
        cout << x << " ";
    cout << endl;

    vector<int> nums1_copy2 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2_copy2 = {2, 4, 6};
    mergeInPlace(nums1_copy2, m, nums2_copy2, n);
    cout << "After Approach 2 (In-place): ";
    for (int x : nums1_copy2)
        cout << x << " ";
    cout << endl;

    return 0;
}
