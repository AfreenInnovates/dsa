#include <bits/stdc++.h>
using namespace std;

int approach1_linearsearch(vector<int> nums)
{
    int n = nums.size();
    int minimum = nums.at(0);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < minimum)
        {
            minimum = nums[i];
        }
    }
    return minimum;
}

int approach2_binarysearch1(vector<int> nums)
{
    int n = nums.size();
    int minimum = INT_MAX;
    int low = 0, high = n - 1;
    int mid = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;

        minimum = min(nums[low], minimum);

        if (nums[low] <= nums[mid])
        {
            minimum = min(nums[low], minimum);
            low = mid + 1;
        }
        else
        {
            minimum = min(nums[mid], minimum);
            high = mid - 1;
        }
    }
    return minimum;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int minimum1 = approach1_linearsearch(nums);
    cout << "Minimum element (Approach 1 - Linear Search): " << minimum1 << endl;

    int minimum2 = approach2_binarysearch1(nums);
    cout << "Minimum element (Approach 2 - Binary Search): " << minimum2 << endl;

    return 0;
}
