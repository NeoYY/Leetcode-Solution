/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.



Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4


Solution similar to the previous question.

*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort( nums.begin(), nums.end() );
        int sum = nums[0] + nums[1] + nums[2], diff = abs( sum - target ), n = nums.size();
        if ( target > 0 && nums.back() < 0 ) return nums[n - 1] + nums[n - 2] + nums[n - 3];
        for ( int i = 0; i < n - 2; ++i )
        {
            if ( nums[i] * 3 > target ) return min( sum, nums[i] + nums[i + 1] + nums[i + 2] );
            int j = i + 1, k = n - 1;
            while ( j < k )
            {
                int tmp = nums[i] + nums[j] + nums[k];
                int newDiff = abs( tmp - target );
                if ( newDiff < diff )
                {
                    diff = newDiff;
                    sum = tmp;
                }
                if ( tmp < target ) ++j;
                else --k;
            }
        }
       return sum;
    }
};

//Optimized
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort( nums.begin(), nums.end() );
        int sum = nums[0] + nums[1] + nums[2], diff = abs( sum - target ), n = nums.size();
        if ( target > 0 && nums.back() < 0 ) return nums[n - 1] + nums[n - 2] + nums[n - 3];
        for ( int i = 0; i < n - 2; ++i )
        {
            if ( nums[i] * 3 > target ) return min( sum, nums[i] + nums[i + 1] + nums[i + 2] );
            if ( i > 0 && nums[i] == nums[i - 1] ) continue;
            int j = i + 1, k = n - 1;
            while ( j < k )
            {
                int tmp = nums[i] + nums[j] + nums[k];
                if ( tmp == target ) return tmp;
                int newDiff = abs( tmp - target );
                if ( newDiff < diff )
                {
                    diff = newDiff;
                    sum = tmp;
                }
                if ( tmp < target )
                {
                    while ( ++j < k && nums[j] == nums[j - 1] );
                }
                else
                {
                    while ( j < --k && nums[k] == nums[k + 1] );
                }
            }
        }
       return sum;
    }
};
