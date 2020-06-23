/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

Solution one is DFS, recursive
Two using set to get rid of repeated element

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if ( n == 0 ) return res;
        AddP( n, n , "", res );
        return res;
    }
    void AddP( int l, int r, string out, vector<string>& res )
    {
        if ( l > r ) return;
        if ( l == 0 && r == 0 )
        {
            res.push_back( out );
            return;
        }
        if ( l > 0 ) AddP( l - 1, r, out + '(', res );
        if ( r > 0 ) AddP( l, r - 1, out + ')', res );
    }
};


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> res;
        if ( n == 0 ) res.insert( "" );
        else
        {
            vector<string> temp( generateParenthesis( n - 1 ) );
            for ( auto &a: temp )
            {
                for ( int j = 0; j < a.size(); ++j )
                {
                    if ( a[j] == '(' )
                    {
                        a.insert(a.begin() + j + 1, '(' );
                        a.insert(a.begin() + j + 2, ')' );
                        res.insert( a );
                        a.erase( a.begin() + j + 1, a.begin() + j + 3 );
                    }

                }
                res.insert( "()" + a );
            }
        }
        return vector<string>( res.begin(), res.end() );
    }
};
