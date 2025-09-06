#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Row-wise Binary Search
----------------------------------
For each row:
  - Skip if target is outside [first, last] range.
  - Otherwise binary search that row.

Time Complexity: O(n * log m)
    - Up to n rows, binary search takes O(log m) each.
Space Complexity: O(1)
*/
bool binaryS(vector<int> matrix, int target)
{
    int low = 0, high = matrix.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (matrix[mid] == target)
            return true;
        else if (matrix[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        if (target < matrix[i][0] || target > matrix[i][m - 1])
            continue;
        if (binaryS(matrix[i], target))
            return true;
    }
    return false;
}

/*
Approach 2: Staircase Search (Top-Right Corner)
-----------------------------------------------
Start from top-right element:
  - If element == target -> found
  - If element > target -> move left
  - If element < target -> move down

Requires: each row and each column sorted in ascending order.

Time Complexity: O(n + m)
    - Each step eliminates one row or one column.
Space Complexity: O(1)
*/
bool searchMatrixApproach2(vector<vector<int>> matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int i = 0, j = m - 1; // start at top-right
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            j--;
        else
            i++;
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
        cout << "  Row-wise Binary Search -> " << searchMatrix(matrix, t) << "\n";
        cout << "  Staircase Search       -> " << searchMatrixApproach2(matrix, t) << "\n\n";
    }

    return 0;
}
