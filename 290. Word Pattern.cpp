/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.

Solution one using hash map, first check whether the string is according to the
pattern, then check if it is repeated. Last check if this str has the same length as pattern.
Solution is optimized, clearer and shorter.
Can be done using two hash map
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> hash;
        int count = 0;
        for ( int i = 0; i < pattern.size(); ++i )
        {
            string temp;
            for ( int j = 0; j < str.size(); j++ )
            {
                if ( str[j] == ' ' )
                {
                    count++;
                    str = str.substr( j + 1 );
                    break;
                }
                temp += str[j];
            }
            if ( hash.find( pattern[i] ) == hash.end() )
            {
                for ( auto &a: hash )
                {
                    if ( a.second == temp ) return false;
                }
                hash[pattern[i]] = temp;
            }
            else
            {
                if ( hash[pattern[i]] != temp ) return false;
            }
        }
        return count == pattern.size() - 1;
    }
};


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> hash;
        int i = 0, n = pattern.size();
        istringstream tp( str );
        for ( string temp; tp >> temp; ++i )
        {
            if ( i >= n ) continue;
            if ( hash.count( pattern[i] ) )
            {
                if (hash[pattern[i]] != temp ) return false;
            } else {
                for ( auto &a: hash )
                {
                    if ( a.second == temp ) return false;
                }
                hash[pattern[i]] = temp;
            }
        }
        return i == n;
    }
};
