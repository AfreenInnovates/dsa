#include <bits/stdc++.h>
using namespace std;

/*
    Approach 1: Using map to count frequencies
    ------------------------------------------
    Steps:
        1. Traverse the array and count frequency of each element using a map.
        2. Iterate over the map to find the element whose frequency > n/2.

    Time Complexity:
        Step 1: O(n log n)
            - We perform 'n' insert/update operations in a std::map.
            - Each operation costs O(log k) where k ≤ n (number of distinct keys).
            - Worst case: O(n log n).
        Step 2: O(n) in worst case (if all elements are distinct).

        Overall: O(n log n)

    Space Complexity:
        O(n) → storing counts of up to n distinct elements.
*/
int approach1(vector<int> nums)
{
    int n = nums.size();
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }

    for (auto num : mpp)
    {
        if (num.second > (n / 2))
        {
            return num.first;
        }
    }

    return -1;
}

/*
    Approach 2: Boyer–Moore Voting Algorithm
    -----------------------------------------
    Steps:
        1. Maintain a candidate element (el) and a counter (count).
        2. Traverse the array:
            - If count is 0, set current element as candidate and count = 1.
            - If current element == candidate, increment count.
            - Otherwise, decrement count.
        3. Candidate at the end is the majority element.

    Time Complexity:
        O(n) → single pass through the array.

    Space Complexity:
        O(1) → only a few integer variables used.
*/
int approach2(vector<int> nums)
{
    int n = nums.size();
    int count = 0;
    int el = -1;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            el = nums[i];
            count = 1;
        }
        else if (nums[i] == el)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return el;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "\nApproach 1 (Map, O(n log n) time, O(n) space): "
         << approach1(nums) << "\n";

    cout << "Approach 2 (Boyer–Moore, O(n) time, O(1) space): "
         << approach2(nums) << "\n";

    return 0;
}
