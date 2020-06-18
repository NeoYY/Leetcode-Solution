/*

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

Solution one using brute force, O(N2)
Solution two using Manacher algo O(N)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0, len = 0;
        string res = "";
        for ( int i = 0; i < s.size(); i++ )
        {
            int len1 = verify( s, i, i );
            int len2 = verify( s, i, i + 1 );
            len = max( len1, len2 );
            if ( len > end - start )
            {
                end = i + len / 2;
                start = i - ( len - 1 ) / 2;
            }
        }
        res = s.substr( start, end - start + 1 );
        // C++ substr(start, len). start is the location of the first para,
        // len is the len of the substring.
        return res;
    }
    int verify( string& s, int start, int end )
    {
        while ( start >= 0 && end < s.size() && s[start] == s[end] )
        {
            start--;
            end++;
        }
        return end - start - 1;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
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
            if ( resLen < p[i] )
            {
                resLen = p[i];
                resCen = i;
            }
        }
        return s.substr( ( resCen - resLen ) / 2, resLen - 1 );
        //Center = ( resCen - resLen ) / 2
        //Len = resLen -1;
        //This is based on the algorithm
    }
};
