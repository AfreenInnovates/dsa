#include <bits/stdc++.h>
using namespace std;

/*
    Method 1: Brute Force
    ---------------------
    Idea:
        - Use a simple comparison-based sort (e.g., selection sort) to reorder 0s, 1s, and 2s.
        - Compare every element with every other element and swap if out of order.
        - This is the most inefficient method for this special case but works for any integers.

    Time Complexity:
        Outer loop: runs (n - 1) times
        Inner loop: runs up to (n - i - 1) times
        Total comparisons ≈ n*(n-1)/2  → O(n^2)

    Space Complexity:
        O(1) → in-place sorting

    Drawback:
        - Unnecessary overhead because the problem is highly restricted (only 0, 1, 2).
*/
void brute_force(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[i])
                swap(nums[i], nums[j]);
        }
    }

    for (int num : nums)
        cout << num << " ";
    cout << "\n";
}

/*
    Method 2: Better (Counting Sort for 0,1,2)
    ------------------------------------------
    Idea:
        - Count the number of 0s, 1s, and 2s
        - Overwrite the array based on these counts

    Time Complexity:
        Step 1: Count → O(n)
        Step 2: Fill zeros → O(zeroes) ≤ O(n)
        Step 3: Fill ones → O(ones) ≤ O(n)
        Step 4: Fill twos → O(twos) ≤ O(n)
        Total ≈ 2n → O(n)

    Space Complexity:
        O(1) → only three counters
*/
void better(vector<int> arr)
{
    int n = arr.size();
    int zeroes = 0, ones = 0, twos = 0;

    for (auto num : arr)
    {
        if (num == 0)
            zeroes++;
        else if (num == 1)
            ones++;
        else
            twos++;
    }

    // Fill zeros
    for (int i = 0; i < zeroes; i++)
        arr[i] = 0;

    // Fill ones
    for (int i = zeroes; i < zeroes + ones; i++)
        arr[i] = 1;

    // Fill twos
    for (int i = zeroes + ones; i < n; i++)
        arr[i] = 2;

    for (int num : arr)
        cout << num << " ";
    cout << "\n";
}

/*
    Method 3: Optimal (Dutch National Flag Algorithm)
    -------------------------------------------------
    Idea:
        - Maintain three regions:
            low   → end of 0s region
            mid   → current element to process
            high  → start of 2s region
        - Process the mid pointer until it crosses high:
            * nums[mid] == 0 → swap with low, increment both low & mid
            * nums[mid] == 1 → correct place, just increment mid
            * nums[mid] == 2 → swap with high, decrement high (mid stays to recheck swapped value)

    Time Complexity:
        Single pass → O(n)
        Each element processed at most once

    Space Complexity:
        O(1) → only pointers
*/
void optimal(vector<int> nums)
{
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else // nums[mid] == 2
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }

    for (int num : nums)
        cout << num << " ";
    cout << "\n";
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (only 0, 1, or 2): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nBrute Force (O(n^2)) output: ";
    brute_force(arr);

    cout << "Better (Counting Sort, O(n)) output: ";
    better(arr);

    cout << "Optimal (Dutch National Flag, O(n)) output: ";
    optimal(arr);

    return 0;
}
