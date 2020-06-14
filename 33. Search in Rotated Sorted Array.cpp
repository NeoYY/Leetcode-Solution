/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Solution B_Search
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return b_search( nums, 0, nums.size() - 1, target );
    }
    int b_search( vector<int>& nums, int s, int e, int target )
    {
        if ( s > e ) return -1;
        int mid = s + ( e - s ) / 2;
        if ( nums[mid] == target ) return mid;
        //If from 0 -> mid is ordered, do b search
        if ( nums[mid] >= nums[0] )
        {
            if ( target <= nums[mid] && target >= nums[0] )
                return b_search( nums, 0, mid - 1, target );
            else
                return b_search( nums, mid + 1, e, target );
        }
        //otherwise, find the point where to start the other ordered search
        //and start B_Search
        else
        {
            if ( target >= nums[mid] && target <= nums[e] )
                return b_search( nums, mid + 1, e, target );
            else
                return b_search( nums, s, mid - 1, target );
        }
        return -1;
    }
};
