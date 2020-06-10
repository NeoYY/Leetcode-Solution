/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

The first solution using ^, second using hash map, need extra space.

*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int m = 0;
        for ( int i = 0; i < nums.size(); ++i )
        {
            m = nums[i] ^ m;
        }
        return m;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        for ( int num: nums )
        {
            if( !hash[num] ) hash[num] = 1;
            else hash.erase( num );
        }
        return hash.begin()->first;
    }
};
