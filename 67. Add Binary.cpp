/* Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

Basically, this is print out the sum of two binary number that stored as string
Two ways of implementation
First one is done by purely string/char
The second one is a optimized implementation that use int instead of string

Below are the codes
*/

//Implementation one
class Solution {
public:
    string addBinary(string a, string b) {
    //corner case when one of the string is 0
        if ( a == "0" ) return b;
        else if ( b == "0" ) return a;
        int size_a = a.length() - 1;
        int size_b = b.length() - 1;
        char c_a, c_b;
        //carry bit
        int cb = 0;
        string res = "";
        //first round, computation for the shorter string
        while ( size_a >= 0 && size_b >= 0 )
        {
        c_a = a[size_a];
        c_b = b[size_b];            
            if ( cb == 0 )
            {
                if ( c_a == '1' && c_b =='1' )
                {
                    res = '0' + res;
                    cb = 1;
                }
                else if ( c_a == '1' || c_b == '1' )
                {
                    res = '1' + res;
                    cb = 0;
                }
                else
                {
                    res = '0' + res;
                    cb = 0;           
                }
            }
            else
            {
                if ( c_a == '1' && c_b =='1' )
                {
                    res = '1' + res;
                    cb = 1;
                }
                else if ( c_a == '1' || c_b == '1' )
                {
                    res = '0' + res;
                    cb = 1;
                }
                else
                {
                    res = '1' +res;
                    cb = 0;          
                }

            }
            if ( --size_a >= 0 ) c_a = a[size_a];
            if ( --size_b >= 0 ) c_b = b[size_b];        
        }
        //second round, computation for the longer string
        while ( size_a >= 0 )
        {
            if ( cb == 0 ) res = c_a + res;
            else
            {
                if ( c_a == '1' )
                {
                    cb = 1;
                    res = '0' + res;
                }
                else
                {
                    cb = 0;
                    res = '1' + res;
                }
            }
            if ( --size_a >= 0 ) c_a = a[size_a];
        }
        while ( size_b >= 0 )
        {
            if ( cb == 0 ) res = c_b + res;
            else
            {
                if ( c_b == '1' )
                {
                    cb = 1;
                    res = '0' + res;
                }
                else
                {
                    cb = 0;
                    res = '1' + res;
                }
            }
            if ( --size_b >= 0 ) c_b = b[size_b];
        }
        //if there is a carry bit, add to the first place
        if ( cb == 1 ) res = '1' + res;
        return res;
    }
};


//solution 2, convert the char to int to solve the situation that the length of two input is different
//when converted, "100001" + "10" will be considered as 100001 + 000010;
class Solution {
public:
    string addBinary(string a, string b) {
        int size_a = a.length() - 1;
        int size_b = b.length() - 1;
        //carry bit
        int cb = 0;
        string res = "";
        //use int instead of char
        int temp1 = 0;
        int temp2 = 0;
        //loop end when all digits are added
        while ( size_a >=0 || size_b >= 0 )
        {
            // '0' || '1' - '0' will be integer 1 or 0
            temp1 = ( size_a >= 0 )? a[size_a--] - '0' : 0;
            temp2 = ( size_b >= 0 )? b[size_b--] - '0' : 0;
            // 3 % 2 will be 1
            // 2,3 / 2 will be 1
            res = to_string( ( temp1 + temp2 + cb ) % 2 ) + res;
            cb = ( ( temp1 + temp2 + cb ) / 2 );            
        }
        return cb == 1 ? '1' + res : res;
    }
};
