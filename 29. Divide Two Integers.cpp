/*

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.


Solution one is brute force, consider every single corner case and get the result.
Solution two using bit munipulation, while using long

*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if ( dividend == INT_MIN && divisor == -1 ) return INT_MAX;
        if ( divisor == 1 ) return dividend;
        int ct = 0;
        if ( dividend > 0 && divisor > 0 )
        {
            if ( dividend == divisor ) return 1;
            while ( dividend > divisor )
            {
                dividend -= divisor;
                ++ct;
            }
        }
        else if ( dividend > 0 && divisor < 0 )
        {
            if ( -dividend == divisor ) return -1;
            dividend = - dividend;
            while ( dividend < divisor )
            {
                dividend -= divisor;
                ++ct;
            }
            ct = -ct;
        }
        else if ( dividend < 0 && divisor > 0 )
        {
            if ( dividend == -divisor ) return -1;
            divisor = -divisor;
            while ( dividend <= divisor )
            {
                dividend -= divisor;
                ++ct;
            }
            ct = -ct;
        }
        else
        {
            if ( dividend == divisor ) return 1;
            while ( dividend <= divisor )
            {
                dividend -= divisor;
                ct++;
            }
        }
        return ct;
    }
};



class Solution {
public:
    int divide(int dividend, int divisor) {
        if ( dividend == INT_MIN && divisor == -1 ) return INT_MAX;
        long did = labs( dividend ), div = labs( divisor ), res = 0;
        int sign = ( ( dividend < 0 ) ^ ( divisor < 0 ) ) ? -1: 1;
        while( did >= div )
        {
            long temp = div, m = 1;
            while ( temp << 1 <= did )
            {
                temp <<= 1;
                m <<= 1;
            }
            did -= temp;
            res += m;
        }
        return res * sign;
    }
};
