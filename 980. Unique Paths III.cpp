/*

On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.



Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation:
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.


Note:

1 <= grid.length * grid[0].length <= 20

SOlution using DFS
*/

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int res = 0;
        for ( int i = 0; i < grid.size(); ++i )
        {
            for ( int j = 0; j < grid[0].size(); ++j )
            {
                if ( grid[i][j] == 1 )
                {
                    res = getRes( grid, i, j );
                    break;
                }
            }
        }
        return res;
    }
private:
    int getRes( vector<vector<int>>& grid, int i, int j )
    {
        if ( i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1 ) return 0;
        if ( grid[i][j] == 2 )
        {
            for ( int m = 0; m < grid.size(); ++m )
            {
                for ( int n = 0; n < grid[0].size(); ++n )
                {
                    if ( grid[m][n] == 0 ) return 0;
                }
            }
            return 1;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;
        int res = getRes( grid, i - 1, j );
        res += getRes( grid, i, j - 1 );
        res += getRes( grid, i + 1, j );
        res += getRes( grid, i, j + 1 );
        grid[i][j] = temp;
        return res;
    }
};
