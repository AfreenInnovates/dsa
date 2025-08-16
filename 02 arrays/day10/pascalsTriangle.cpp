#include <bits/stdc++.h>
using namespace std;

//----------------------------------------------------
// Function: nCr
// Time Complexity: O(r) → loop runs r times
// Space Complexity: O(1) → only uses constant extra space
//----------------------------------------------------
int nCr(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

//----------------------------------------------------
// Function: printRow
// Purpose: Prints a single row of Pascal's Triangle
// Time Complexity: O(r) → prints r elements
// Space Complexity: O(1) → constant extra variables
//----------------------------------------------------
void printRow(int r)
{
    int res = 1;
    cout << res << " ";
    for (int i = 1; i < r; i++)
    {
        res = res * (r - i);
        res = res / i;
        cout << res << " ";
    }
    cout << endl;
}

//----------------------------------------------------
// Variation 1: Generate Pascal's Triangle using nCr()
// Time Complexity: O(n^3) → n rows × n elements × O(n) for nCr
// Space Complexity: O(n^2) → storing the full triangle
//----------------------------------------------------
vector<vector<int>> pascalTriangle_v1(int n)
{
    vector<vector<int>> ans;

    for (int row = 1; row <= n; row++)
    {
        vector<int> tempLst;
        for (int col = 1; col <= row; col++)
        {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

//----------------------------------------------------
// Variation 2: Generate Pascal's Triangle iteratively
// Time Complexity: O(n^2) → each row is built using previous row
// Space Complexity: O(n^2) → storing the full triangle
//----------------------------------------------------
vector<vector<int>> pascalTriangle_v2(int n)
{
    vector<vector<int>> ans;

    for (int row = 0; row < n; row++)
    {
        vector<int> tempLst(row + 1, 1); // all ones initially
        for (int col = 1; col < row; col++)
        {
            tempLst[col] = ans[row - 1][col - 1] + ans[row - 1][col];
        }
        ans.push_back(tempLst);
    }
    return ans;
}

int main()
{
    int n, r;

    // Input for nCr
    cout << "Enter n and r for nCr: ";
    cin >> n >> r;
    cout << "nCr(" << n << ", " << r << ") = " << nCr(n, r) << "\n\n";

    // Input for printing a row
    int rowNum;
    cout << "Enter row number to print: ";
    cin >> rowNum;
    cout << "Row " << rowNum << " of Pascal's Triangle:\n";
    printRow(rowNum);
    cout << "\n";

    // Input for full Pascal's Triangle
    int size;
    cout << "Enter number of rows for Pascal's Triangle: ";
    cin >> size;

    cout << "\nPascal's Triangle (Variation 1 - nCr method):\n";
    auto triangle1 = pascalTriangle_v1(size);
    for (auto &row : triangle1)
    {
        for (auto &val : row)
            cout << val << " ";
        cout << "\n";
    }
    cout << "\n";

    cout << "Pascal's Triangle (Variation 2 - Iterative method):\n";
    auto triangle2 = pascalTriangle_v2(size);
    for (auto &row : triangle2)
    {
        for (auto &val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}
