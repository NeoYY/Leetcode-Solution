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
        Quick_Sort( nums, 0, nums.size() - 1 );
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
    void Quick_Sort( vector<int>& nums, int low, int high )
    {
        if ( low >= high ) return;
        int pa = Partition( nums, low, high );
        Quick_Sort( nums, low, pa - 1 );
        Quick_Sort( nums, pa + 1, high );
    }
    void Find_Mid( vector<int>& nums, int low, int high )
    {
        int i = low;
        int j = high;
        int k = low + ( high - low ) / 2;
        if ( nums[i] > nums[k] ) swap( nums[i], nums[k] );
        if ( nums[i] > nums[j] ) swap( nums[j], nums[j] );
        if ( nums[k] > nums[j] ) swap( nums[k], nums[j] );
        swap( nums[k], nums[j] );
    }
    int Partition( vector<int>& nums, int low, int high )
    {
        Find_Mid( nums, low, high );
        int l = low;
        int h = high;
        int temp = nums[high];
        while ( l != h )
        {
            while ( nums[l] <= temp && l < h ) l++;
            while ( nums[h] >= temp && l < h ) h--;
            if ( l < h ) swap( nums[l], nums[h] );
        }
        nums[high] = nums[l];
        nums[l] = temp;
        return l;
    }
};
