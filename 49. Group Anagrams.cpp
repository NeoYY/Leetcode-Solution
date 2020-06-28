/*

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.


Solution one using built in sort, and store in an unordered_map
Solution two using hand write sorting to optimize
Solution three using a trick to avoid copying and speed up
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for ( auto &a: strs )
        {
            string temp = a;
            sort( temp.begin(), temp.end() );
            hash[temp].push_back( a );
        }
        vector<vector<string>> res;
        for ( auto &a: hash )
        {
            res.push_back( a.second );
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for ( auto &a: strs )
        {
            hash[CountSort( a )].push_back( a );
        }
        vector<vector<string>> res;
        for ( auto &a: hash )
        {
            res.push_back( a.second );
        }
        return res;
    }
private:
    string CountSort( string& s )
    {
        int n = s.size();
        int counter[26] = {0};
        for ( int i = 0; i < n; ++i )
        {
            counter[s[i] - 'a']++;
        }
        string temp;
        for ( int i = 0; i < 26; ++i )
        {
            temp += string( counter[i], i + 'a' );
        }
        return temp;
    }
};




class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hash;
        vector<vector<string>> res;
        for ( auto &a: strs )
        {
            string t = a;
            sort( t.begin(), t.end() );
            if ( !hash.count( t ) )
            {
                hash[t] = res.size();
                res.push_back( {} );
            }
            res[hash[t]].push_back( a );
        }
        return res;
    }
};
