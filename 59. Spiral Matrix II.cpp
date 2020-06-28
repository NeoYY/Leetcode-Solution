/*

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]


Solution one using looping index
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if ( n == 0 ) return {};
        vector<vector<int>> res( n, vector<int>( n ) );
        int left = 0, right = n - 1, up = 0, down = n - 1, ct = 1;
        while ( 1 )
        {
            for ( int i = left; i <= right; ++i ) res[up][i] = ct++;
            if ( up++ > down ) break;
            for ( int j = up; j <= down; ++j ) res[j][right] = ct++;
            if ( right-- < left ) break;
            for ( int i = right; i >= left; --i ) res[down][i] = ct++;
            if ( down-- < up ) break;
            for ( int j = down; j >= up; --j ) res[j][left] = ct++;
            if ( left++ > right ) break;
        }
        return res;
    }
};
