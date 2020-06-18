/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
             Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Solution one is the same as two, just in another expression.
*/

class Solution {
public:
    int addDigits(int num) {
        if ( num % 9 == 0 && num > 0 ) return 9;
        return num % 9;
    }
};

class Solution {
public:
    int addDigits(int num) {
        return num == 0 ? 0 : ( num - 1 ) % 9 + 1;
    }
};
