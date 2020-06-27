/*

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.


Solution one using multiplication
      48 * 56 =
      48
      56
  -----------
      48
     24
     40
    20
------------------
   2688

size i * size j at most i + j;
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        int m = num1.size(), n = num2.size();
        vector<int> temp( m + n, 0 );
        for ( int i = m - 1; i >= 0; --i )
        {
            for ( int j = n - 1; j >=0; --j )
            {
                int p1 = i + j, p2 = i + j + 1;
                int multi = ( num1[i] - '0' ) * ( num2[j] - '0' );
                int sum = temp[p2] + multi;
                temp[p2] = sum % 10;
                temp[p1] += sum / 10;
            }
        }
        for ( int a: temp )
        {
            if ( !res.empty() || a != 0 ) res.push_back( a + '0' );
        }
        return res.empty() ? "0" : res;
    }
};
