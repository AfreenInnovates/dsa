#include <bits/stdc++.h>
using namespace std;

int firstIndex(vector<int> &nums, int target)
{
    int n = (int)nums.size();
    int first = -1;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1; // search left half
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
    return first;
}

int lastIndex(vector<int> &nums, int target)
{
    int n = (int)nums.size();
    int last = -1;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1; // search right half
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

int main()
{
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter target: ";
    cin >> target;

    int first = firstIndex(nums, target);
    int last = lastIndex(nums, target);

    cout << "[" << first << ", " << last << "]" << endl;

    return 0;
}