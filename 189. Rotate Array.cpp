/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?


Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


Constraints:

1 <= nums.length <= 2 * 10^4
It's guaranteed that nums[i] fits in a 32 bit-signed integer.
k >= 0



Solution one using brute force, it does not work in C++
Two using extra space
Three using rotation.
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        if( k == 0 ) return;
        int temp, previous;
        for ( int i = 0; i < k; i++ )
        {
            previous = nums[size - 1];
            for ( int j = 0; j < size; j++ )
            {
                temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        if ( k == 0 ) return;
        vector<int> temp( size );
        for ( int i = 0; i < size; i++ )
        {
            temp[ ( i + k ) % size ] = nums[i];
        }
        nums = temp;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        if( k == 0 ) return;
        int count = 0;
        //We need this loop as when ( curr + k ) % size = 0, the array may not be fully rotated.
        for ( int i = 0; count < size; i++ )
        {
            int curr = i;
            int prev = nums[i];
            do
            {
                int next = ( curr + k ) % size;
                int temp = nums[next];
                nums[next] = prev;
                curr = next;
                prev = temp;
                count++;
            } while( i != curr );
        }
    }
};
