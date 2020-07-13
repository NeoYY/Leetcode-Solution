/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

SOlution one using 2D Dp
Solution two using 1D Dp
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if ( obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1 ) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long>> Dp( m + 1, vector<long>( n + 1, 0 ) );
        Dp[0][1] = 1;
        for ( int i = 1; i <= m; ++i )
        {
            for ( int j = 1; j <= n; ++j )
            {
                if ( obstacleGrid[i - 1][j - 1] == 1 )
                {
                    Dp[i][j] = 0;
                    continue;
                }
                Dp[i][j] = Dp[i - 1][j] + Dp[i][j - 1];
            }
        }
        return Dp[m][n];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if ( obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1 ) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<long> Dp( n, 0 );
        Dp[0] = 1;
        for ( int i = 0; i < m; ++i )
        {
            for ( int j = 0; j < n; ++j )
            {
                if ( obstacleGrid[i][j] == 1 )
                {
                    Dp[j] = 0;
                    continue;
                }
                if ( j > 0 ) Dp[j] += Dp[j - 1];
            }
        }
        return Dp[n - 1];
    }
};
