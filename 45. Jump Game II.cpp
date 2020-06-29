/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.


Solutions are all based on Greedy, just in different form.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), ct = 0, prev = 0, end = 0;
        for ( int i = 0; i < n - 1; ++i )
        {
            end = max( end, i + nums[i] );
            if ( i == prev )
            {
                ++ct;
                prev = end;
                if ( prev >= n - 1 ) break;
            }
        }
        return ct;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), ct = 0, start = 0, end = 0;
        while ( end < n - 1 )
        {
            ++ct;
            int new_end = end + 1;
            for ( int i = start; i <= end; ++i )
            {
                if ( new_end >= n - 1 ) return ct;
                new_end = max( new_end, i + nums[i] );
            }
            start = end + 1;
            end = new_end;
        }
        return ct;
    }
};
