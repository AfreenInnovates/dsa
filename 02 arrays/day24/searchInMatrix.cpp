#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach
--------------------
Time Complexity: O(n * m)
    - Traverse each of the n rows and m columns.
Space Complexity: O(1)
*/
bool brute_force(vector<vector<int>> &arr, int target)
{
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

/*
Binary Search helper for a single row
-------------------------------------
Time Complexity: O(log m)
Space Complexity: O(1)
*/
bool binaryS(const vector<int> &arr, int target)
{
    int low = 0, high = (int)arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return true;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

/*
Approach 2: Row-wise Binary Search
----------------------------------
For each row, skip if target < first or target > last, else binary search.

Time Complexity: O(n * log m)
    - Up to n rows, binary search takes O(log m) each.
Space Complexity: O(1)
*/
bool approach2(vector<vector<int>> &matrix, int target)
{
    int n = (int)matrix.size();
    if (n == 0)
        return false;
    int m = (int)matrix[0].size();
    if (m == 0)
        return false;

    for (int i = 0; i < n; ++i)
    {
        if (target < matrix[i][0] || target > matrix[i][m - 1])
            continue; // don't run binary search if the target is less than the first element of the row, or greater than the last element of the row, cause it won't be present there. if row elements are 10, 20, 30 : why run it for 40, as 40 is greater than 40 and not less than 10. so it doesn't belong in that range --> skip.
        if (binaryS(matrix[i], target))
            return true;
    }
    return false;
}

/*
Approach 3: Treat matrix as a flattened sorted array
----------------------------------------------------
Assumption: Each row is sorted AND the first element of a row is
greater than the last element of the previous row.

Time Complexity: O(log(n * m))
    - Binary search on n*m elements.
Space Complexity: O(1)
*/
bool approach3(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0, high = (m * n) - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        int midElement = matrix[mid / m][mid % m];

        if (midElement == target)
        {
            return true;
        }
        else if (midElement > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    vector<int> targets = {16, 13, 1, 60, 25};

    cout << boolalpha;
    for (int t : targets)
    {
        cout << "Target " << t << ":\n";
        cout << "  Brute Force   -> " << brute_force(matrix, t) << "\n";
        cout << "  Row BinSearch -> " << approach2(matrix, t) << "\n";
        cout << "  Flatten BinSr -> " << approach3(matrix, t) << "\n\n";
    }

    return 0;
}
