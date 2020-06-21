/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.


Solution one is iterative,
two is recursive
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res{""};
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for ( int i = 0; i < digits.size(); ++i )
        {
            vector<string> temp;
            string tp = dict[digits[i] - '0'];
            for ( int j = 0; j < tp.size(); ++j )
                for ( auto &a: res ) temp.push_back( a + tp[j] );
            res = temp;
        }
        return res;
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        DFSCombine( dict, 0, "", res, digits );
        return res;
    }
    void DFSCombine( vector<string>& dict, int level, string out, vector<string>& res, string digits )
    {
        if ( level == digits.size() )
        {
            res.push_back( out );
            return;
        }
        string temp = dict[digits[level] - '0'];
        for ( int i = 0; i < temp.size(); ++i )
        {
            DFSCombine( dict, level + 1, out + temp[i], res, digits );
        }
    }
};
