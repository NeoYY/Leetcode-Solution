/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

Solution one brute force time limit exceed.
Solution two using hash table;
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for ( int i = 0; i < nums.size(); i++ )
        {
            for ( int j = i + 1; ( j <= i + k ) && j < nums.size() ; j++ )
            {
                if ( nums[i] == nums[j] ) return true;
            }

        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for ( int i = 0; i < nums.size(); i++ )
        {
            if ( hash.find( nums[i] ) == hash.end() )
                hash[nums[i]] = i;
            else
            {
                if ( i - hash[nums[i]] <= k) return true;
                hash[nums[i]] = i;
            }
        }
        return false;
    }
};
