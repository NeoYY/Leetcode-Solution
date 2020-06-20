/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Solution is using iterative, can be done recursive
*/
class Solution {
public:
    string intToRoman(int num) {
        string res = Convert( num );
        return res;
    }
    string Convert( int num )
    {
        string res = "";
        if ( num == 0 ) return res;
        while ( num >= 1000 )
        {
            res += 'M';
            num -= 1000;
        }
        if ( num >= 900 )
        {
            res += "CM";
            num -= 900;
        }
        else if ( num >= 500 && num < 900 )
        {
            res += 'D';
            num -= 500;
        }
        else if ( num >= 400 && num < 500 )
        {
            res += "CD";
            num -= 400;
        }
        while ( num >= 100)
        {
            res += 'C';
            num -= 100;
        }
        if ( num >= 90 )
        {
            res += "XC";
            num -= 90;
        }
        else if ( num >= 50 && num < 90 )
        {
            res += 'L';
            num -= 50;
        }
        else if ( num >= 40 && num < 50 )
        {
            res += "XL";
            num -= 40;
        }
        while ( num >= 10 )
        {
            res += 'X';
            num -= 10;
        }
        if ( num == 9 )
        {
            res += "IX";
            num -= 9;
        }
        else if ( num >=5 && num < 9 )
        {
            res += 'V';
            num -= 5;
        }
        else if ( num == 4 )
        {
            res += "IV";
            num -= 4;
        }
        while ( num > 0 )
        {
            res += 'I';
            num--;
        }
        return res;
    }

};
