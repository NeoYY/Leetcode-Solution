/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".


Create a dictionary to check whether it is a vowel;
*/
// a e i o u
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        unordered_set<char> s1 = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        while ( i < j )
        {
            if ( s1.count( s[i] ) > 0 && s1.count( s[j] ) > 0 )
            {
                swap( s[i], s[j] );
                ++i; --j;
            }
            while ( s1.count( s[i] ) == 0 && i < j) ++i;
            while ( s1.count( s[j] ) == 0 && i < j) --j;
        }
        return s;
    }
};


// a e i o u
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while ( i < j )
        {
            i = s.find_first_of( "aeiouAEIOU", i );
            j = s.find_last_of( "aeiouAEIOU", j );
            if ( i < j ) swap( s[i++], s[j--]);
        }
        return s;
    }
};
