/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2


First solution using unordered_map, second using sorting
First one is faster but will need extra space;
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int, int> hash;
        for ( int i: nums ) hash[i]++;
        for ( auto i: hash )
        {
            if ( i.second > nums.size() / 2 ) return i.first;
        }
        return 0;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element( nums.begin(), nums.begin() + nums.size() / 2, nums.end() );
        return nums[nums.size() / 2];
    }
};
