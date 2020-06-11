/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"


The first solution using extra space, but fast
second one is slower but more space efficient
*/


class Solution {
public:
    string convertToTitle(int n) {
        vector<char> temp = {'Z', 'A', 'B', 'C', 'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
        string res = "";
        while ( n )
        {
            int mod = n % 26;
            res = temp[mod] + res;
            n = ( n - 1 ) / 26;
        }
        return res;
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while ( n )
        {
            if ( !( n % 26 ) )
            {
                res = 'Z' + res;
            }
            else
            {
                char c = 'A' - 1 + n % 26;
                res = c + res;
            }
            n = ( n - 1 ) / 26;
        }
        return res;
    }
};
