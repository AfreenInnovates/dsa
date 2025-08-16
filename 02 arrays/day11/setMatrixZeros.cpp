#include <bits/stdc++.h>
using namespace std;

// --- Approach 1: Mark with -1 ---
void markRow(int row, vector<vector<int>> &matrix, int m)
{
    for (int j = 0; j < m; j++)
    {
        if (matrix[row][j] != 0)
        {
            matrix[row][j] = -1;
        }
    }
}

void markCol(int col, vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][col] != 0)
        {
            matrix[i][col] = -1;
        }
    }
}

void approach1(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // Mark rows and columns with -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(i, matrix, m);
                markCol(j, matrix, n);
            }
        }
    }

    // Replace -1 with 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }
}

// --- Approach 2: Using row[] and col[] ---
void approach2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> row(n, 0), col(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void printMatrix(const vector<vector<int>> &matrix)
{
    for (auto &row : matrix)
    {
        for (auto &val : row)
            cout << val << " ";
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}};

    vector<vector<int>> matrix2 = matrix1;

    cout << "Original Matrix:\n";
    printMatrix(matrix1);

    approach1(matrix1);
    cout << "\nModified Matrix (Approach 1 - mark with -1):\n";
    printMatrix(matrix1);

    approach2(matrix2);
    cout << "\nModified Matrix (Approach 2 - row[] & col[]):\n";
    printMatrix(matrix2);

    return 0;
}
