#include <bits/stdc++.h>
using namespace std;

// time : O(N)
// space : O(1)
int linearApproach(vector<int> nums, int target)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            count++;
        }
    }
    return count;
}

// ---- approach 2 : using first and last occurrence binary search ----
// time : O(2*log N)
// space : O(1)
int firstOccurrence(vector<int> nums, int target)
{
    int n = nums.size();
    int firstIndex = -1;
    int low = 0, high = n - 1, mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            firstIndex = mid;
            high = mid - 1;
        }

        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return firstIndex;
}

int lastOccurrence(vector<int> nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1, mid = 0, lastIndex = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            lastIndex = mid;
            low = mid + 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return lastIndex;
}

pair<int, int> firstAndLastOccurrence(vector<int> nums, int target)
{

    int n = nums.size();
    int first = firstOccurrence(nums, target);
    int last = lastOccurrence(nums, target);

    return {first, last};
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5, 5, 5, 6};
    int target = 5;

    cout << "Array: ";
    for (int x : nums)
        cout << x << " ";
    cout << "\nTarget: " << target << "\n\n";

    int countLinear = linearApproach(nums, target);
    cout << "Count using linear approach: " << countLinear << "\n";

    pair<int, int> occ = firstAndLastOccurrence(nums, target);
    if (occ.first == -1)
    {
        cout << "Target not found using binary search approach.\n";
    }
    else
    {
        int countBinary = occ.second - occ.first + 1;
        cout << "First occurrence index: " << occ.first << "\n";
        cout << "Last occurrence index: " << occ.second << "\n";
        cout << "Count using binary search approach: " << countBinary << "\n";
    }

    return 0;
}