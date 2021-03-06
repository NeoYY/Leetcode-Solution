/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.


Solution is using dp
*/
class NumArray {
public:
    NumArray(vector<int>& nums) {
        dp.resize( nums.size() + 1, 0 );
        for ( int i = 1; i <= nums.size(); ++i )
        {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }
private:
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
