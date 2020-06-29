/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?



Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28


Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.


Solution one using DP
Solution two using the math
Take out m - 1 combination over m + n - 2;
Cmn = n! / m! ( n - m )! 
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> Dp( n, 1 );
        for ( int i = 1; i < m; ++i )
        {
            for ( int j = 1; j < n; ++j )
            {
                Dp[j] += Dp[j - 1];
            }
        }
        return Dp[n - 1];
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        double a = 1, b = 1;
        int small = min( m - 1, n - 1 );
        int large = max( m - 1, n - 1 );
        for ( int i = 1; i <= small; ++i )
        {
            a *= i;
            b *= small + large + 1 - i;
        }
        return ( int )( b / a );
    }
};
