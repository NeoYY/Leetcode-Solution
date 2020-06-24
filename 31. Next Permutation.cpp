/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

Search from the end to the begin
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if ( nums.empty() || nums.size() == 1 ) return;
        int i = nums.size() - 2, j = nums.size() - 1;
        while ( i >= 0 && nums[i + 1] <= nums[i] ) --i;
        if ( i >= 0 )
        {
            while ( nums[j] <= nums[i] ) --j;
            swap( nums[i], nums[j] );
        }
        reverse( nums.begin() + i + 1, nums.end() );
    }
};
