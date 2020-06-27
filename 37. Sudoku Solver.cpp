/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.

Solution using recursive, the point is to check if the char that we are going to
fill in is valid, if it is, then remain it and go to the next one, j + 1, else
go check another char.
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        Solve( board, 0, 0 );
    }
    bool Solve( vector<vector<char>>& board, int i, int j )
    {
        if ( i == 9 ) return true;
        if ( j >= 9 ) return Solve( board, i + 1, 0 );
        if ( board[i][j] != '.' ) return Solve( board, i, j + 1 );
        for ( char c = '1'; c <= '9'; c++ )
        {
            if ( !isValid( board, i, j, c ) ) continue;
            board[i][j] = c;
            if ( Solve( board, i, j + 1 ) ) return true;
            board[i][j] = '.';
        }
        return false;
    }
    bool isValid( vector<vector<char>>& board, int i, int j, char c )
    {
        for ( int x = 0; x < 9; ++x )
        {
            if ( board[x][j] == c ) return false;
            if ( board[i][x] == c ) return false;
            if ( board[i / 3 * 3 + x / 3][j / 3 * 3 + x % 3] == c ) return false;
        }
        return true;
    }
};
