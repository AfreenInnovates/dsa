#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force (Linear Search for each sequence)
--------------------------------------------------------
Logic:
- For each element, check if the next consecutive number exists in the array (linear search).
- Count the length of sequence starting from that number.
- Keep track of the longest sequence found.

Time Complexity: O(n^2)
    - Outer loop runs O(n) times
    - Inner linearSearch takes O(n) in worst case
Space Complexity: O(1)
    - No extra data structures used (apart from a few variables)
*/

// Helper function for linear search
bool linearSearch(vector<int> &nums, int target)
{
    for (int num : nums)
    {
        if (num == target)
            return true;
    }
    return false;
}

int longestConsecutive_bruteforce(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        int count = 1;
        while (linearSearch(nums, x + 1))
        {
            x = x + 1;
            count++;
        }
        longest = max(longest, count);
    }
    return longest;
}

/*
Approach 2: Sorting-based
--------------------------
Logic:
- Sort the array.
- Iterate and count consecutive sequences.
- Skip duplicates.
- Track the longest sequence length.

Time Complexity: O(n log n)
    - Sorting takes O(n log n)
    - Single pass through array O(n)
Space Complexity: O(1)
    - Sorting can be in-place, no extra data structure used
*/
int longestConsecutive_sorting(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    sort(nums.begin(), nums.end());

    int lastSmaller = INT_MIN;
    int count = 0;
    int largest = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] - 1 == lastSmaller)
        {
            count++;
            lastSmaller = nums[i];
        }
        else if (nums[i] != lastSmaller)
        {
            lastSmaller = nums[i];
            count = 1;
        }
        largest = max(largest, count);
    }

    return largest;
}

/*
Approach 3: Optimal using Hash Set
Logic:
- Insert all numbers into an unordered_set for O(1) lookup.
- For each number, check if it's the start of a sequence (previous number not in set).
- Count consecutive sequence length starting from that number.
- Keep track of maximum length.

Time Complexity: O(n)
    - O(n) for inserting into set
    - O(n) for checking sequences (each number visited at most twice)
Space Complexity: O(n)
    - Extra space for unordered_set
*/
int longestConsecutive_hashset(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;

    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        { // starting number
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << "Brute Force: " << longestConsecutive_bruteforce(nums) << endl;
    cout << "Sorting Based: " << longestConsecutive_sorting(nums) << endl;
    cout << "Optimal (HashSet): " << longestConsecutive_hashset(nums) << endl;

    return 0;
}
