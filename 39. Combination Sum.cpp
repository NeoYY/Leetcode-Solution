/*

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]


Solution one using recursion
Solution two using inside recursion, sorting and cutting branch
It can be done in DP, but not incuded, basically,
Create a 3d vector for each res set and iterative
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        Combine( candidates, target, out, res, 0 );
        return res;
    }
    void Combine( vector<int>& candidates, int target, vector<int>& out, vector<vector<int>>& res, int level )
    {
        if ( target < 0 ) return;
        if ( target == 0 )
        {
            res.push_back( out );
            return;
        }
        for ( int i = level; i < candidates.size(); ++i )
        {
            out.push_back( candidates[i] );
            Combine( candidates, target - candidates[i], out, res, i );
            out.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort( candidates.begin(), candidates.end() );
        for ( int i = 0; i < candidates.size(); ++i )
        {
            if ( candidates[i] > target ) break;
            if ( candidates[i] == target )
            {
                res.push_back( { candidates[i] } );
                break;
            }
            vector<int> vec = vector<int>( candidates.begin() + i, candidates.end() );
            vector<vector<int>> temp = combinationSum( vec, target - candidates[i] );
            for ( auto &a: temp)
            {
                a.insert( a.begin(), candidates[i] );
                res.push_back( a );
            }
        }
        return res;
    }
};
