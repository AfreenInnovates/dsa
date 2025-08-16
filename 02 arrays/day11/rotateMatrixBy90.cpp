#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using extra matrix
// Time: O(n*m)
// Space: O(n*m)
vector<vector<int>> rotateMatrixExtra(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> newMat(m, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            newMat[j][n - 1 - i] = mat[i][j];
        }
    }
    return newMat;
}

// Approach 2: In-place rotation (only works for square matrices)
// Time: O(n^2)
// Space: O(1)
void rotateMatrixInPlace(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "Original Matrix:\n";
    for (auto row : mat)
    {
        for (auto val : row)
            cout << val << " ";
        cout << "\n";
    }

    vector<vector<int>> rotated1 = rotateMatrixExtra(mat);
    cout << "\nRotated Matrix (Approach 1 - Extra Space):\n";
    for (auto row : rotated1)
    {
        for (auto val : row)
            cout << val << " ";
        cout << "\n";
    }

    rotateMatrixInPlace(mat);
    cout << "\nRotated Matrix (Approach 2 - In-place):\n";
    for (auto row : mat)
    {
        for (auto val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}
