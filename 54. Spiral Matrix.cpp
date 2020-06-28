/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Solution one is using a dictionary for moving
Solution two using loop index
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<vector<int>> dic = { { 0 ,1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        int row = matrix.size();
        if ( row == 0 ) return res;
        int col = matrix[0].size();
        if ( col == 0 ) return res;

        vector<int> Steps = { col, row - 1 };

        int Pos = 0, PRow = 0, PCol = -1;
        while ( Steps[Pos % 2] )
        {
            for ( int i = 0; i < Steps[Pos % 2]; ++i )
            {
                PRow += dic[Pos][0];
                PCol += dic[Pos][1];
                res.push_back( matrix[PRow][PCol] );
            }
            --Steps[Pos % 2];
            Pos = ( Pos + 1 ) % 4;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if ( matrix.empty() || matrix[0].empty() ) return {};
        vector<int> res;
        int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;
        while ( 1 )
        {
            for ( int i = left; i <= right; ++i )
            {
                res.push_back( matrix[up][i] );
            }
            if ( ++up > down ) break;
            for ( int j = up; j <= down; ++j )
            {
                res.push_back( matrix[j][right] );
            }
            if ( --right < left ) break;
            for ( int i = right; i >= left; --i )
            {
                res.push_back( matrix[down][i] );
            }
            if ( --down < up ) break;
            for ( int j = down; j >= up; --j )
            {
                res.push_back( matrix[j][left] );
            }
            if ( ++left > right ) break;
        }
        return res;
    }
};
