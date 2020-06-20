/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

Solution one using iterative
Solution two using two pointers, in-place swaping
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for ( int i = nums.size() - 1; i >= 0; --i )
        {
            if ( nums[i] == 0 )
            {
                nums.erase( nums.begin() + i );
                count++;
            }
        }
        for ( int i = 0; i < count; ++i )
        {
            nums.push_back( 0 );
        }
    }
};



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for ( int i = 0, j = 0; i < nums.size(); ++i )
        {
            if ( nums[i] )
            {
                swap( nums[i], nums[j++] );
            }
        }
    }
};
