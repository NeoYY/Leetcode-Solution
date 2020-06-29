/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5

Solution one using greedy,
two using DP
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), max_dis = 0;
        for ( int i = 0; i < n; ++i )
        {
            if ( max_dis < i ) return false;
            max_dis = max( max_dis, i + nums[i] );
        }
        return true;
    }
};

//DP will TLE in leetcode
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> jump( n, false );
        jump[n - 1] = true;
        for ( int i = n - 2; i >= 0; --i )
        {
            for ( int j = 0; j <= nums[i] && j + i < n; ++j )
            {
                if ( jump[i + j] )
                {
                    jump[i] = true;
                    break;
                }
            }
        }
        return jump[0];
    }
};


//This verison of DP will pass
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> Dp( n, 0 );
        for ( int i = 1; i < n; ++i )
        {
            Dp[i] = max( Dp[i - 1], nums[i - 1] ) - 1;
            if ( Dp[i] < 0 ) return false;
        }
        return true;
    }
};
