#include <bits/stdc++.h>
using namespace std;

// ------------------- Brute Force O(n^2) -------------------
pair<int, vector<pair<int, int>>> reversePairsBrutePairs(vector<int> &nums)
{
    int n = nums.size();
    vector<pair<int, int>> pairs;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > 2LL * nums[j])
            {
                pairs.push_back({nums[i], nums[j]});
            }
        }
    }

    return {pairs.size(), pairs};
}

// ------------------- Merge Sort Based O(n log n) -------------------
int countAndMergeWithPairs(vector<int> &arr, int low, int mid, int high, vector<pair<int, int>> &pairs)
{
    int count = 0;
    int j = mid + 1;

    // Count reverse pairs and store them
    for (int i = low; i <= mid; i++)
    {
        int temp_j = j;
        while (temp_j <= high && (long long)arr[i] > 2LL * arr[temp_j])
        {
            pairs.push_back({arr[i], arr[temp_j]});
            temp_j++;
        }
        count += (temp_j - (mid + 1));
    }

    // Merge step
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];

    return count;
}

pair<int, vector<pair<int, int>>> mergeSortAndCountWithPairs(vector<int> &arr, int low, int high, vector<pair<int, int>> &pairs)
{
    if (low >= high)
        return {0, {}};

    int mid = (low + high) / 2;
    int count = 0;

    count += mergeSortAndCountWithPairs(arr, low, mid, pairs).first;
    count += mergeSortAndCountWithPairs(arr, mid + 1, high, pairs).first;
    count += countAndMergeWithPairs(arr, low, mid, high, pairs);

    return {count, pairs};
}

// ------------------- MAIN -------------------
int main()
{
    vector<int> nums = {1, 3, 2, 3, 1};

    cout << "Array elements: ";
    for (int x : nums)
        cout << x << " ";
    cout << "\n\n";

    // Brute Force
    auto [countBrute, pairsBrute] = reversePairsBrutePairs(nums);
    cout << "Brute Force:\nCount = " << countBrute << "\nPairs = ";
    for (auto &p : pairsBrute)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n\n";

    // Merge Sort
    vector<int> numsCopy = nums;
    vector<pair<int, int>> pairsMerge;
    auto [countMerge, _] = mergeSortAndCountWithPairs(numsCopy, 0, numsCopy.size() - 1, pairsMerge);

    cout << "Merge Sort:\nCount = " << countMerge << "\nPairs = ";
    for (auto &p : pairsMerge)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";

    cout << "Sorted array using Merge Sort: ";
    for (int x : numsCopy)
        cout << x << " ";
    cout << "\n";

    return 0;
}
