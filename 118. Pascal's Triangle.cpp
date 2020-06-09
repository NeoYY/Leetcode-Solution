/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if ( numRows == 0 ) return res;
        vector<int> first;
        first.push_back( 1 );
        res.push_back( first );
        for ( int i = 1; i < numRows; i++ )
        {
            first.clear();
            first.push_back( 1 );
            for ( int j = 1; j < i; j++ )
            {
                first.push_back( res[i - 1][j - 1] + res[i - 1][j] );
            }
            first.push_back( 1 );
            res.push_back( first );
        }
        return res;
    }
};


