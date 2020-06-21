/*

Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]


Solution one using two pointers, traditional Solution
Two using the characteristic of set
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        int n = nums.size();
        sort( nums.begin(), nums.end() );
        if ( nums.empty() || ( target < 0 && nums.front() > 0 ) || ( target > 0 && nums.back() < 0 ) ) return {};
        for ( int i = 0; i < n - 3; ++i )
        {
            for ( int j = i + 1; j < n - 2; ++j )
            {
                int k = j + 1, z = n - 1;
                while ( k < z )
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[z];
                    if ( target == sum )
                    {
                        vector<int> temp = { nums[i], nums[j], nums[k], nums[z] };
                        res.insert( temp );
                        ++k; --z;
                    }
                    else if ( target < sum )
                    {
                        --z;
                    }
                    else ++k;
                }
            }
        }
        return vector<vector<int>>( res.begin(), res.end() );
    }
};

//Recursive
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        int n = nums.size();
        sort( nums.begin(), nums.end() );
        if ( nums.empty() || ( target < 0 && nums.front() > 0 ) || ( target > 0 && nums.back() < 0 ) ) return {};
        for ( int i = 0; i < n - 3; ++i )
        {
            for ( int j = i + 1; j < n - 2; ++j )
            {
                int k = j + 1, z = n - 1;
                while ( k < z )
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[z];
                    if ( target == sum )
                    {
                        vector<int> temp = { nums[i], nums[j], nums[k], nums[z] };
                        res.insert( temp );
                        ++k; --z;
                    }
                    else if ( target < sum )
                    {
                        --z;
                    }
                    else ++k;
                }
            }
        }
        return vector<vector<int>>( res.begin(), res.end() );
    }
};
