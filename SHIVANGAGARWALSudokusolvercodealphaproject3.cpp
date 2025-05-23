#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
private:
    bool issafe(vector<vector<char>>& board, int row, int col, char dig) {
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig)
                return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig)
                return false;
        }
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;
        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (board[i][j] == dig)
                    return false;
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {
        if (row == 9)
            return true;

        int nextrow = row, nextcol = col + 1;
        if (nextcol == 9) {
            nextrow = row + 1;
            nextcol = 0;
        }

        if (board[row][col] != '.')
            return helper(board, nextrow, nextcol);

        for (char dig = '1'; dig <= '9'; dig++) {
            if (issafe(board, row, col, dig)) {
                board[row][col] = dig;
                if (helper(board, nextrow, nextcol))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    cout << "Enter the Sudoku puzzle (use '.' for empty cells):\n";

    // Take input from user
    for (int i = 0; i < 9; i++) {
        string row;
        cout << "Row " << i + 1 << ": ";
        cin >> row;
        while (row.length() != 9) {
            cout << "Each row must contain exactly 9 characters (digits 1-9 or '.'): ";
            cin >> row;
        }
        for (int j = 0; j < 9; j++) {
            board[i][j] = row[j];
        }
    }
	// Create object and solve the Sudoku
	Solution solver;
	solver.solveSudoku(board);
	// Print the solved Sudoku
	cout << "\nSolved Sudoku:\n";
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j) 
		{
			cout << board[i][j] << " ";
        }
		cout << endl;
    }

    return 0;
}
