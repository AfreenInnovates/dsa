#include <bits/stdc++.h>
using namespace std;

/*
    Approach 1: Merge both arrays fully, then find median
    ----------------------------------------------------
    Time Complexity:
        - Merging two arrays → O(m + n)
        - Total = O(m + n)

    Space Complexity:
        - Extra array nums3 of size (m + n)
        - Total = O(m + n)
*/
double findMedianSortedArrays_approach1(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    vector<int> nums3;
    nums3.reserve(m + n);

    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
            nums3.push_back(nums1[i++]);
        else
            nums3.push_back(nums2[j++]);
    }

    while (i < m)
        nums3.push_back(nums1[i++]);
    while (j < n)
        nums3.push_back(nums2[j++]);

    int size = nums3.size();
    if (size % 2 == 0)
    {
        int mid = size / 2;
        return (nums3[mid] + nums3[mid - 1]) / 2.0;
    }
    else
    {
        int mid = size / 2;
        return nums3[mid];
    }
}

/*
    Approach 2: Two-pointer merge until median
    ------------------------------------------
    Time Complexity:
        - Still O(m + n) in worst case (all elements considered)

    Space Complexity:
        - No extra array
        - Total = O(1)
*/
double findMedianSortedArrays_approach2(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    int total = m + n;
    int index1 = total / 2;  // middle index
    int index2 = index1 - 1; // left of middle (for even case)

    int indexEl1 = -1, indexEl2 = -1;
    int count = 0;

    int i = 0, j = 0;

    while (i < m && j < n)
    {
        int val;
        if (nums1[i] < nums2[j])
            val = nums1[i++];
        else
            val = nums2[j++];

        if (count == index1)
            indexEl1 = val;
        if (count == index2)
            indexEl2 = val;
        count++;
    }

    while (i < m)
    {
        int val = nums1[i++];
        if (count == index1)
            indexEl1 = val;
        if (count == index2)
            indexEl2 = val;
        count++;
    }
    while (j < n)
    {
        int val = nums2[j++];
        if (count == index1)
            indexEl1 = val;
        if (count == index2)
            indexEl2 = val;
        count++;
    }

    if (total % 2 == 1) // odd length
        return indexEl1;
    else // even length
        return (indexEl1 + indexEl2) / 2.0;
}

int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << "Case 1: nums1 = {1,3}, nums2 = {2}" << endl;
    cout << "Approach1 (O(m+n), O(m+n)) Median: " << findMedianSortedArrays_approach1(nums1, nums2) << endl;
    cout << "Approach2 (O(m+n), O(1))   Median: " << findMedianSortedArrays_approach2(nums1, nums2) << endl;

    cout << endl;

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};

    cout << "Case 2: nums3 = {1,2}, nums4 = {3,4}" << endl;
    cout << "Approach1 (O(m+n), O(m+n)) Median: " << findMedianSortedArrays_approach1(nums3, nums4) << endl;
    cout << "Approach2 (O(m+n), O(1))   Median: " << findMedianSortedArrays_approach2(nums3, nums4) << endl;

    return 0;
}
