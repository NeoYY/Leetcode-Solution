/*

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

Solution using hash map
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if ( s.size() != t.size() ) return false;
        unordered_map<char, int> hash;
        for ( int i = 0; i < s.size(); i++ ) hash[s[i]]++;
        for ( int i = 0; i < t.size(); i++ )
        {
            if ( hash.find( t[i] ) == hash.end() || hash[t[i]] == 0 ) return false;
            hash[t[i]]--;
        }
        return true;
    }
};
//Optimize a little
class Solution {
public:
    bool isAnagram(string s, string t) {
        if ( s.size() != t.size() ) return false;
        unordered_map<char, int> hash;
        for ( int i = 0; i < s.size(); i++ ) hash[s[i]]++;
        for ( int i = 0; i < t.size(); i++ )
        {
            if ( hash.find( t[i] ) == hash.end() ) return false;
            if ( --hash[t[i]] == 0 ) hash.erase( t[i] );
        }
        return true;
    }
};


// With char, array is faster, but if for unicode, hash table will be perferer
class Solution {
public:
    bool isAnagram(string s, string t) {

     if(s.size()!=t.size())return false;
		 if(s.size()==0&&t.size()==0)return true;
		 int Sum[26]={0,0,0};
		 for(int i=0;i<s.size();i++)
			 Sum[s[i]-'a']++;
		 for(int j=0;j<t.size();j++)
			 Sum[t[j]-'a']--;
		 for(int j=0;j<26;j++)
			 if(Sum[j]!=0)return false;
		 return true;

    }
};
