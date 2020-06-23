/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

Solution one using iterative
Solution two using istringstream
*/
class Solution {
public:
    string reverseWords(string s) {
        if ( s == "" ) return s;
        for ( int i = 0; i < s.size() - 1; ++i )
        {
            int j = i;
            while ( s[i] != ' ' && i != s.size() - 1 ) ++i;
            if ( s[i] == ' ' ) reverse( s.begin() + j, s.begin() + i );
            else reverse( s.begin() + j, s.end() );
        }
        return s;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        if ( s == "" ) return s;
        string res = "", t = "";
        istringstream is( s );
        while ( is >> t )
        {
            int size = t.size() - 1;
            int i = 0;
            while ( i < size )
            {
                swap( t[i++], t[size--] );
            }
            res = res + t + " ";
        }
        res.pop_back();
        return res;
    }
};
