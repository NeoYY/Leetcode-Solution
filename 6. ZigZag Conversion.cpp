/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I

Solution one use a extra vector to store the string and add them together
Solution two use the formula that interval of the element is
interval = 2 * numRows - 2;
Position of element that not belong to 0/numRows - 1 is
j( index of last element that is in black line ) + interval - 2 * i( which row )


*/
class Solution {
public:
    string convert(string s, int numRows) {
        if ( numRows <= 1 ) return s;
        vector<string> temp( numRows );
        int n = s.size();
        int i = 0;
        while ( i < n )
        {
            for ( int pos = 0; pos < numRows && i < n; ++pos )
            {
                temp[pos] += s[i++];
            }
            for ( int pos = numRows - 2; pos >= 1 && i < n; --pos )
            {
                temp[pos] += s[i++];
            }
        }
        string res;
        for ( auto &t: temp ) res += t;
        return res;
    }
};


class Solution {
public:
    string convert(string s, int numRows) {
        if ( numRows <= 1 ) return s;
        int n = s.size(), interval = 2 * numRows - 2;
        string res = "";
        for ( int i = 0; i < numRows; i++ )
        {
            for ( int j = i; j < n; j += interval )
            {
                res += s[j];
                int pos = j + interval - 2 * i ;
                if ( i != 0 && i != numRows - 1 && pos < n ) res += s[pos];
            }
        }
        return res;
    }
};
