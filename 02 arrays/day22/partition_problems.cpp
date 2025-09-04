/*
    Problems implemented:
    1. Book Allocation
    2. Split Array Largest Sum
    3. Painter's Partition Problem

    Core Idea: All three are the same underlying problem —
               partitioning an array into k contiguous parts,
               minimizing the maximum sum among the partitions.

    Time Complexity: O(N log S)
        - N = size of array
        - S = sum of all elements - max element
        Binary search on the answer (log S) and greedy check per iteration (O(N))

    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// ========== Book Allocation ==========
int countStudents(vector<int> &nums, int pages)
{
    int studentCount = 1;
    long long pagesCount = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (pagesCount + nums[i] <= pages)
        {
            pagesCount += nums[i];
        }
        else
        {
            studentCount++;
            pagesCount = nums[i];
        }
    }
    return studentCount;
}

int book_allocation(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    int ans = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = countStudents(nums, mid);

        if (cnt <= k)
        {
            ans = mid; // feasible
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // not feasible
        }
    }
    return ans;
}

// ========== Split Array Largest Sum ==========
int cntArrays(vector<int> &nums, int m)
{
    int arrayNumber = 1;
    long long arraySum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (arraySum + nums[i] <= m)
        {
            arraySum += nums[i];
        }
        else
        {
            arrayNumber++;
            arraySum = nums[i];
        }
    }
    return arrayNumber;
}

int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    int ans = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int countArrays = cntArrays(nums, mid);

        if (countArrays > k)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

// ========== Painter's Partition ==========
int countPainters(vector<int> &boards, int maxLen)
{
    int painters = 1;
    long long currLen = 0;

    for (int len : boards)
    {
        if (currLen + len <= maxLen)
        {
            currLen += len;
        }
        else
        {
            painters++;
            currLen = len;
        }
    }
    return painters;
}

int paintersPartition(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    int ans = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = countPainters(boards, mid);

        if (cnt <= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

// ========== Main ==========
int main()
{
    vector<int> nums = {12, 34, 67, 90};
    int k1 = 2;

    vector<int> nums2 = {7, 2, 5, 10, 8};
    int k2 = 2;

    vector<int> boards = {10, 20, 30, 40};
    int painters = 2;

    cout << "Book Allocation (minimum pages) = " << book_allocation(nums, k1) << endl;
    cout << "Split Array Largest Sum = " << splitArray(nums2, k2) << endl;
    cout << "Painter's Partition (minimum time) = " << paintersPartition(boards, painters) << endl;

    return 0;
}
