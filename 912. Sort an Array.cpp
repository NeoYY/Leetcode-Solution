/*

Given an array of integers nums, sort the array in ascending order.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
 

Constraints:

1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000


Solution one is merge sort, Second is quick sort
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        Merge_Sort( nums, 0, nums.size() - 1 );
        return nums;
    }
    void Merge_Sort( vector<int>& nums, int start, int end )
    {
        if ( start >= end ) return;
        int mid = start + ( end - start ) / 2;
        Merge_Sort( nums, start, mid );
        Merge_Sort( nums, mid + 1, end );
        Merge( nums, start, mid, end );
    }
    void Merge( vector<int>& nums, int start, int mid, int end )
    {
        int s = start;
        int m = mid + 1;
        int i = 0;
        vector<int> temp( end - start + 1 );
        while ( s <= mid && m <= end)
        {
            if( nums[s] <= nums[m] ) temp[i++] = nums[s++];
            else temp[i++] = nums[m++];
        }
        while ( s <= mid ) temp[i++] = nums[s++];
        while ( m <= end ) temp[i++] = nums[m++];
        for ( int j = 0; j < temp.size(); j++ )
        {
            nums[start++] = temp[j];
        }
    }
};
