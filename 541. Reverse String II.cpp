/*

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]

Solution discuss different possibilities
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0, size = s.size() - 1;
        if ( size < k )
        {
            while( i < size ) swap( s[i++], s[size--] );
            return s;
        }
        if ( size < 2 * k )
        {
            size = k - 1;
            while( i < size ) swap( s[i++], s[size--] );
            return s;
        }
        for ( int j = 0; j < size; j += 2 * k )
        {
            i = j;
            int b = min ( size, j + k - 1 );
            while ( i < b )
            {
                swap( s[i++], s[b--] );
            }

        }
        return s;
    }
};


//Optimized, first couple of lines are redundant
class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0, size = s.size() - 1;
        for ( int j = 0; j < size; j += 2 * k )
        {
            i = j;
            int b = min ( size, j + k - 1 );
            while ( i < b )
            {
                swap( s[i++], s[b--] );
            }

        }
        return s;
    }
};
