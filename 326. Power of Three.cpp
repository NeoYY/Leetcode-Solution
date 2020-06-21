/*
Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
Follow up:
Could you do it without using any loop / recursion?

Solution one using log, time complexity base on the log operation
Solution two is tricky, using magic number.
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && ( log10( n ) / log10( 3 ) ) - ( int ) ( log10( n ) / log10( 3 ) ) == 0;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
