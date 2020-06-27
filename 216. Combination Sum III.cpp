/*

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]

Solution one using helper recursion
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        helper( res, out, 1, k, n );
        return res;
    }
    void helper( vector<vector<int>>& res, vector<int>& out, int level, int k, int n )
    {
        if ( n < 0 || out.size() > k ) return;
        if ( n == 0 && out.size() == k )
        {
            res.push_back( out );
            return;
        }
        for ( int i = level; i <= 9; ++i )
        {
            if ( i > n ) break;
            out.push_back( i );
            helper( res, out, i + 1, k, n - i );
            out.pop_back();
        }
    }
};
