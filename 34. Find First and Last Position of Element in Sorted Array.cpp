/*

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Solution using binary search !! Fake one, worst case O(N)
SOlution using two binary search
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = { -1, -1 };
        if ( nums.empty() ) return res;
        int i = 0, j = nums.size() - 1, n = nums.size() - 1;
        while ( i <= j )
        {
            int mid = i + ( j - i ) / 2;
            if ( nums[mid] == target )
            {
                int temp = mid;
                while ( temp >= 0 && nums[temp] == target )
                {
                    --temp;
                }
                if ( temp < 0 ) res[0] = 0;
                else res[0] = temp + 1;
                temp = mid;
                while ( temp <= n && nums[temp] == target )
                {
                    ++temp;
                }
                if ( temp > n ) res[1] = n;
                else res[1] = temp - 1;
                break;
            }
            else if ( nums[mid] < target )
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = { -1, -1 };
        if ( nums.empty() ) return res;
        int i = 0, j = nums.size();
        while ( i < j )
        {
            int mid = i + ( j - i ) / 2;
            if ( nums[mid] < target )
            {
                i = mid + 1;
            }
            else j = mid;
        }
        if ( j == nums.size() || nums[j] != target ) return res;
        res[0] = j;
        j = nums.size();
        while ( i < j )
        {
            int mid = i + ( j - i ) / 2;
            if ( nums[mid] <= target )
            {
                i = mid + 1;
            }
            else j = mid;
        }
        res[1] = j - 1;
        return res;
    }
};
