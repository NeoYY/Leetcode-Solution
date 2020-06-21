/*

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0

Solution one using mask
Solution two shift m, n, until they are equal
Solution three is recursive
Solution four using n & ( n - 1 )

*/


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if ( m == 0 ) return 0;
        unsigned int d = 0x7fffffff;
        while ((m & d) != (n & d)) {
            d <<= 1;
        }
        return m & d;
    }
};


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if ( m == 0 || n == 0 ) return 0;
        int i = 0;
        while ( m != n )
        {
            m >>= 1;
            n >>= 1;
            i++;
        }
        return m << i;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return (n > m) ? (rangeBitwiseAnd(m / 2, n / 2) << 1) : m;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while ( n > m )
        {
          n = n & ( n - 1 );
        }
        return n;
    }
};
