#include <bits/stdc++.h>
using namespace std;

int findRowWithMaxEle(vector<vector<int>> &mat, int n, int colNumber)
{
    int rowIndex = 0;
    int maxEle = mat[0][colNumber];
    for (int i = 1; i < n; i++)
    {
        if (mat[i][colNumber] > maxEle)
        {
            maxEle = mat[i][colNumber];
            rowIndex = i;
        }
    }
    return rowIndex;
}
vector<int> findPeak(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = m - 1;

    if (mat.empty() || mat[0].empty())
        return {-1, -1};
    while (low <= high)
    {
        int mid = (low + high) / 2;

        int maxRow = findRowWithMaxEle(mat, n, mid);

        // to check if midVal is greater than its immediate left and right values
        int midVal = mat[maxRow][mid];

        int leftVal = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
        int rightVal = (mid + 1 <= m - 1) ? mat[maxRow][mid + 1] : -1;

        if (midVal > leftVal && midVal > rightVal)
        {
            return {maxRow, mid};
        }
        else if (midVal < leftVal)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}