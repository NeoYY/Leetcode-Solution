/*

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]


Solution one using set, and swap
Solution two using DFS recursion, use a target array to store the
element that already been checked

Solution using swap and recursion, it use j to record whether before
i has repeated element
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> temp;
        helper( temp, nums, 0 );
        return vector<vector<int>>( temp.begin(), temp.end() );
    }
    void helper( set<vector<int>>& temp, vector<int>& nums, int start )
    {
        if ( start >= nums.size() ) temp.emplace( nums );
        for ( int i = start; i < nums.size(); ++i )
        {
            if ( i != start && nums[i] == nums[start] ) continue;
            swap( nums[i], nums[start] );
            helper( temp, nums, start + 1 );
            swap( nums[i], nums[start] );
        }

    }
};


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> temp;
        vector<int> out, target( nums.size(), 0 );
        sort( nums.begin(), nums.end() );
        helper( temp, nums, 0, out, target );
        return temp;
    }
    void helper( vector<vector<int>>& temp, vector<int>& nums, int start, vector<int>& out,
               vector<int>& target )
    {
        if ( start >= nums.size() )
        {
            temp.push_back( out );
            return;
        }
        for ( int i = 0; i < nums.size(); ++i )
        {
            if ( target[i] == 1 ) continue;
            if ( i > 0 && nums[i] == nums[i - 1] && target[i - 1] == 0 ) continue;
            target[i] = 1;
            out.push_back( nums[i] );
            helper( temp, nums, start + 1, out, target );
            out.pop_back();
            target[i] = 0;
        }

    }
};


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> temp;
        helper( temp, nums, 0 );
        return temp;
    }
    void helper( vector<vector<int>>& temp, vector<int>& nums, int start )
    {
        if ( start >= nums.size() )
        {
            temp.push_back( nums );
            return;
        }
        for ( int i = start; i < nums.size(); ++i )
        {
            int j = i - 1;
            while ( j >= start && nums[j] != nums[i] ) --j;
            if ( j != start - 1 ) continue;
            swap( nums[i], nums[start] );
            helper( temp, nums, start + 1 );
            swap( nums[i], nums[start] );
        }
    }
};
