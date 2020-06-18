/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?


The first solution is using sum of n - sum of nums
The second solution is using ^
Can be done in binary search
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for ( auto &a: nums )
        {
            sum += a;
        }
        return 0.5 * ( 1 + size ) * size - sum;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for ( int i = 0; i < nums.size(); i++ )
        {
            res ^= ( i + 1 ) ^ nums[i];
        }
        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        int left = 0, right = nums.size();
        while ( left < right )
        {
            int mid = left + ( right - left ) / 2;
            if ( mid < nums[mid] ) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
