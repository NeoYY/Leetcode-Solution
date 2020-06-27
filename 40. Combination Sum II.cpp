/*

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]


Solution using recursive, similiar to #39, except call i + 1 instead of i;
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort( candidates.begin(), candidates.end() );
        helper( candidates, 0, out, res, target );
        return res;
    }
    void helper( vector<int>& candidates, int level, vector<int>& out, vector<vector<int>>& res,
                int target )
    {
        if ( target < 0 ) return;
        if ( target == 0 )
        {
            res.push_back( out );
            return;
        }
        for ( int i = level; i < candidates.size(); ++i )
        {
            if ( i > level && candidates[i] == candidates[i - 1] ) continue;
            out.push_back( candidates[i] );
            helper( candidates, i + 1, out, res, target - candidates[i] );
            out.pop_back();
        }
    }
};
