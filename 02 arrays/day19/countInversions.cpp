#include <bits/stdc++.h>
using namespace std;

// ------------------- Brute Force O(n^2) -------------------
int reversePairsBrute(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > 2LL * nums[j]) // 2LL avoids overflow
            {
                count++;
            }
        }
    }
    return count;
}

// ------------------- Merge Sort Based O(n log n) -------------------
int countAndMerge(vector<int> &arr, int low, int mid, int high)
{
    int count = 0;

    // Count reverse pairs before merging
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && (long long)arr[i] > 2LL * arr[j])
        {
            j++;
        }
        count += (j - (mid + 1));
    }

    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return count;
}

int mergeSortAndCount(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0;

    int mid = (low + high) / 2;
    int count = 0;

    count += mergeSortAndCount(arr, low, mid);
    count += mergeSortAndCount(arr, mid + 1, high);
    count += countAndMerge(arr, low, mid, high);

    return count;
}

// ------------------- MAIN -------------------
int main()
{
    vector<int> nums = {1, 3, 2, 3, 1};

    cout << "Array elements: ";
    for (int x : nums)
        cout << x << " ";
    cout << "\n";

    int revCountBrute = reversePairsBrute(nums);
    cout << "Number of reverse pairs (Brute Force) = " << revCountBrute << "\n";

    vector<int> numsCopy = nums;
    int revCountMerge = mergeSortAndCount(numsCopy, 0, numsCopy.size() - 1);
    cout << "Number of reverse pairs (Merge Sort) = " << revCountMerge << "\n";

    cout << "Sorted array using Merge Sort: ";
    for (int x : numsCopy)
        cout << x << " ";
    cout << "\n";

    return 0;
}
