/*

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?

Solution one using n&(n - 1) for power of 2, and power of 4 - 1 % 3 == 0
Solution two using power of 4 & 0x01010101010101010101010101010101 == num
010.... == 0x55555555
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && ( num & ( num - 1 ) ) == 0 && ( num - 1 ) % 3 == 0;
    }
};

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && ( num & ( num - 1 ) ) == 0 && ( num & 0x55555555 ) == num;
    }
};
