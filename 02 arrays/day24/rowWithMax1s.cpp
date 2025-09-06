#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach
--------------------
Time Complexity: O(n * m)
    - We scan all rows and all columns (n rows × m columns).
Space Complexity: O(1)
*/
int bruteForce(vector<vector<int>> arr)
{
    int n = arr.size();    // number of rows
    int m = arr[0].size(); // number of columns

    int maxCounts = -1;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int rowCount1s = 0;
        for (int j = 0; j < m; j++)
        {
            rowCount1s += arr[i][j];
        }

        if (rowCount1s > maxCounts)
        {
            maxCounts = rowCount1s;
            index = i;
        }
    }
    return index;
}

/*
Binary Search Approach (assumes each row is sorted: all 0s first, then 1s)
---------------------------------------------------------------------------
Time Complexity: O(n * log m)
    - For each row, binary search takes O(log m).
    - Done for n rows → O(n log m).
Space Complexity: O(1)
*/
int lowerBound(vector<int> arr, int m, int x)
{
    int low = 0, high = m - 1;
    int ans = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
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

int approach2(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int count_max = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int count_ones = m - lowerBound(arr[i], m, 1);
        if (count_ones > count_max)
        {
            count_max = count_ones;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> arr = {
        {0, 0, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1}};

    cout << "Using Brute Force: Row with maximum 1s is " << bruteForce(arr) << endl;
    cout << "Using Binary Search: Row with maximum 1s is " << approach2(arr) << endl;

    return 0;
}
