/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.


Solution one using 1D vector for DP
Solution two using constant space;
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if ( grid.empty() || grid[0].empty() ) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> Dp( n, INT_MAX );
        Dp[0] = 0;
        for ( int i = 0; i < m; ++i )
        {
            for ( int j = 0; j < n; ++j )
            {
                if ( j == 0 ) Dp[j] += grid[i][j];
                else Dp[j] = grid[i][j] + min( Dp[j], Dp[j - 1] );
            }
        }
        return Dp[n - 1];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if ( grid.empty() || grid[0].empty() ) return 0;
        int m = grid.size(), n = grid[0].size();
        for ( int i = 0; i < m; ++i )
        {
            for ( int j = 0; j < n; ++j )
            {
                if ( i == 0 && j == 0 ) continue;
                int up = ( i == 0 ) ? INT_MAX : grid[i - 1][j];
                int left = ( j == 0 ) ? INT_MAX : grid[i][j - 1];
                grid[i][j] += min( up, left );
            }
        }
        return grid.back().back();
    }
};
