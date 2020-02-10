/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].


This way is using unordered_map as hash table to do it 


Below is the code */



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res;
        for ( int i = 0; i < nums.size(); ++i )
        {
            int FindThisNum = target - nums[i];
            //This store the key， to find if the key exists
            auto it = hash.find( FindThisNum );
            //If the key exists, it will find the pair that store key FindThisNum
            //Or it will go to the end of the hash
            if ( it != hash.end() )
            {
                res.push_back( it->second );
                res.push_back( i );
                return res;
            }
            //Not found, add this index and key value to the hash map
            hash[nums[i]] = i;
        }
        return res;
    }
};
