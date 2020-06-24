/*

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


Solution one is Recursive DFS
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out, flag( nums.size(), 0 );
        PerMu( nums, res, out, flag, 0 );
        return res;
    }
    void PerMu( vector<int>& nums, vector<vector<int>>& res, vector<int>& out, vector<int>& flag, int level )
    {
        if ( level >= nums.size() )
        {
            res.push_back( out );
            return;
        }
        for ( int i = 0; i < nums.size(); ++i )
        {
            if ( flag[i] == 1 ) continue;
            flag[i] = 1;
            out.push_back( nums[i] );
            PerMu( nums, res, out, flag, level + 1 );
            flag[i] = 0;
            out.pop_back();
        }

    }
};


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        PerMu( nums, res, 0 );
        return res;
    }
    void PerMu( vector<int>& nums, vector<vector<int>>& res, int level )
    {
        if ( level >= nums.size() )
        {
            res.push_back( nums );
            return;
        }
        for ( int i = level; i < nums.size(); ++i )
        {
            swap( nums[i], nums[level] );
            PerMu( nums, res, level + 1 );
            swap( nums[i], nums[level] );
        }
    }
};
