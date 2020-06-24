/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5


Example 2:

Input: 3
Output: False

Solution one is two pointer;
Solution two is fancy
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0, j = sqrt( c );
        while ( i <= j )
        {
            if ( i * i > INT_MAX - j * j) return false;
            int temp = i * i + j * j;
            if ( temp == c ) return true;
            if ( temp < c ) ++i;
            if ( temp > c ) --j;
        }
        return false;
    }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; ++i) {
            if (c % i != 0) continue;
            int cnt = 0;
            while (c % i == 0) {
                ++cnt;
                c /= i;
            }
            if (i % 4 == 3 && cnt % 2 != 0) return false;
        }
        return c % 4 != 3;
    }
};
