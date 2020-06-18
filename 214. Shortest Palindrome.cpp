/*
Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: "abcd"
Output: "dcbabcd"

The first solution using Manacher algorithm
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        int mx = 0, id = 0, resCen = 0, resLen = 0;
        string temp = "$#";
        for ( int i = 0; i < s.size(); i++ )
        {
            temp += s[i];
            temp += '#';
        }
        vector<int> p( temp.size(), 0 );
        for ( int i = 1; i < temp.size(); i++ )
        {
            p[i] = mx > i ? min( p[id * 2 - i], mx - i ) : 1;
            while ( temp[i + p[i]] == temp[i - p[i]] ) ++p[i];
            if ( mx < p[i] + i )
            {
                mx = p[i] + i;
                id = i;
            }
        }
        int pos;
        for (int i = temp.size() - 2; i; i--) {
            if ( i == p[i] ) {
                pos = p[i] - 1;
                break;
            }
        }
        string tail = s.substr( pos );
        reverse( tail.begin(), tail.end() );
        return tail + s;
    }
};
