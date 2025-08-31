#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{
    // check column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // check upper-left diagonal
    // both row and col keeps decreasing
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // check upper-right diagonal
    // row keeps decreasing and col keeps increasing
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';           // place queen
            nQueens(board, row + 1, n, ans); // recurse
            board[row][col] = '.';           // backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.')); // n x n board filled with '.'
    nQueens(board, 0, n, ans);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << "\n\n";

    for (auto &sol : solutions)
    {
        for (auto &row : sol)
        {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
