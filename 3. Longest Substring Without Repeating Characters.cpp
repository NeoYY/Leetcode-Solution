/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

This first solution is using hash map

Second Solution is using vector, which is faster.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if ( s == "" ) return 0;
        int res = 0;
        int temp = 0;
        int left = -1;
        unordered_map<char, int> hash;
        for ( int i = 0; i < (int)s.size(); i++ )
        {
            if ( hash.find( s[i] ) == hash.end() )
            {
                hash[s[i]] = i;
                temp++;
            }
            else
            {
                if ( hash[s[i]] >= left )
                    left = hash[s[i]];
                res = max( res, temp );
                temp = i - left;
                hash[s[i]] = i;
            }
        }
        if ( hash.size() == s.size() ) return hash.size();
        return max( res, temp );
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if ( s == "" ) return 0;
        int res = 0, temp = 0;
        int i = 0, j = -1, pt = 0;
        vector<int> index( 128, -1 );
        for( i = 0; i < s.size(); ++i )
        {
            if ( index[s[i]] != -1 )
            {
                temp = i - j;
                res = max( temp, res );
                j = index[s[i]];
                if ( j < pt ) j = pt;
                else pt = j;
            }
            index[s[i]] = i;
        }
        temp = i - j;
        return max( temp, res ) - 1;
    }
};
