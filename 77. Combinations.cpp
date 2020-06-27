/*

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]


Solution one using helper function recursion
Solution two using self recursion, C( n, k ) = C( n - 1, k - 1 ) + C( n - 1, k );
Solution three using a trick
Increase right first, then add left.



*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        helper( res, out, 1, n, k );
        return res;
    }
    void helper( vector<vector<int>>& res, vector<int> out, int level, int n, int k )
    {
        if ( out.size() == k )
        {
            res.push_back( out );
            return;
        }
        for ( int i = level; i <= n; ++i )
        {
            out.push_back( i );
            helper( res, out, i + 1, n, k );
            out.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if ( k > n || k < 0 ) return {};
        if ( k == 0 ) return {{}};
        vector<vector<int>> res = combine( n - 1, k - 1 );
        for ( auto &a: res ) a.push_back( n );
        for ( auto &a: combine( n - 1, k ) ) res.push_back( a );
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if ( k > n || k < 0 ) return {};
        if ( k == 0 ) return {{}};
        vector<vector<int>> res;
        vector<int> out( k, 0 );
        int i = 0;
        while ( i >= 0 )
        {
            out[i]++;
            if ( out[i] > n ) --i;
            else if ( i == k - 1 ) res.push_back( out );
            else
            {
                ++i;
                out[i] = out[i - 1];
            }
        }
        return res;
    }
};
