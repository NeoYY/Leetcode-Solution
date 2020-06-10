/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/


class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for ( int i = 0; i < s.size(); ++i ) 
        {
            if ( isalnum( s[i] ) ) temp += tolower( s[i] );
        }
        for ( int i = 0; i < temp.size()/2; ++i)
        {
            if ( temp[i] != temp[temp.size() - 1 - i] ) return false;    
        }
        return true;
    }
};
