#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// time : O(N^2) -> 81 iterations (for 9x9 board)
// space : O(1) -> max 27 sets * 9 elements each = 243 chars (constant)
bool isValidSudoku(vector<vector<char>> &board)
{
    vector<unordered_set<char>> rows(9), cols(9), boxes(9);

    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            char val = board[r][c];

            cout << "Checking cell (" << r << "," << c << ") with value: " << val << endl;

            if (val == '.')
                continue;

            // Row check
            if (rows[r].count(val))
            {
                cout << "Duplicate " << val << " found in row " << r << endl;
                return false;
            }
            rows[r].insert(val);
            cout << "Inserted " << val << " into row " << r << endl;

            // Column check
            if (cols[c].count(val))
            {
                cout << "Duplicate " << val << " found in column " << c << endl;
                return false;
            }
            cols[c].insert(val);
            cout << "Inserted " << val << " into column " << c << endl;

            // Box check
            int boxId = (r / 3) * 3 + (c / 3);
            if (boxes[boxId].count(val))
            {
                cout << "Duplicate " << val << " found in box " << boxId << endl;
                return false;
            }
            boxes[boxId].insert(val);
            cout << "Inserted " << val << " into box " << boxId << endl;
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '3', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    if (isValidSudoku(board))
    {
        cout << "Sudoku board is valid" << endl;
    }
    else
    {
        cout << "Sudoku board is invalid" << endl;
    }

    return 0;
}
