#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach:
1. Flatten the matrix into a 1D array.
2. Sort the array.
3. Return the middle element (median).

Time Complexity: O(m * n * log(m * n))
    - Flattening = O(m * n)
    - Sorting = O(m * n * log(m * n))
Space Complexity: O(m * n) for the flattened array
*/
int bruteForceApproach(vector<vector<int>> &arr, int m, int n)
{
    vector<int> arr2;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr2.push_back(arr[i][j]);
        }
    }

    sort(arr2.begin(), arr2.end());

    return arr2[(m * n) / 2]; // median element
}

/*
Helper: upperBound
Finds index of first element > x in sorted row.

Time Complexity: O(log n) for each row
Space Complexity: O(1)
*/
int upperBound(vector<int> &arr, int x, int n)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
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

/*
Helper: countSmallEqual
Counts how many elements in matrix are <= x.

Time Complexity: O(m * log n)
    - Each row uses upperBound in O(log n)
    - For m rows → O(m log n)
Space Complexity: O(1)
*/
int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += upperBound(matrix[i], x, m);
    }
    return count;
}

/*
Binary Search Approach:
1. Binary search on the value range [min, max].
2. For each mid, count how many numbers are <= mid.
3. Narrow range until median found.

Time Complexity: O(log(MaxVal - MinVal) * m * log n)
    - Outer binary search on value range.
    - Each iteration checks m rows using upper_bound (log n).
Space Complexity: O(1)
*/
int binarySearchApproach(vector<vector<int>> &matrix, int m, int n)
{
    int low = INT_MAX, high = INT_MIN;

    for (int i = 0; i < m; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (m * n) / 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);

        if (smallEqual <= req)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    vector<vector<int>> arr(m, vector<int>(n));
    cout << "Enter row-wise sorted matrix elements:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int bruteResult = bruteForceApproach(arr, m, n);
    int binaryResult = binarySearchApproach(arr, m, n);

    cout << "Brute Force Median: " << bruteResult << endl;
    cout << "Binary Search Median: " << binaryResult << endl;

    return 0;
}
