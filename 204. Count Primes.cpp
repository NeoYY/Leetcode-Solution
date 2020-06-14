/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Solution one using brute force

Notes: No overthinking, overwise will not pass.


Solution two use sqrt can reduce the computation time, this work, but will not work on leetcode.
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> temp( n, 1 );
        int res = 0;
        for ( int i = 2; i < n; i++ )
        {
            if ( !temp[i] ) continue;
            res++;
            for ( int j = 2; i * j < n; j++ )
            {
                temp[i * j] = 0;
            }
        }
        return res;
    }
};

//This is the best, wiredly not work on leetcode.s
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> temp( n, 0 );
        int res = 0;
        temp[0] = 1;
        temp[1] = 1;
        for ( int i = 2; i <= sqrt( n ); ++i )
        {
            if ( temp[i] )
            {
                continue;
            }
            for ( int k = i * i; k < n; k += i )
            {
                temp[k] = 1;
            }

        }
        for ( int i = 0; i < temp.size(); i++ )
        {
            if ( !temp[i] ) res++;
        }
        return res;
    }
};
