/*

Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

上面的写法略为复杂，我们尝试着来优化一下，根据上面的分析，所有的字符可以分为六大类，空格，符号，数字，小数点，自然底数和其他字符，我们需要五个标志变量，num, dot, exp, sign分别表示数字，小数点，自然底数和符号是否出现，numAfterE表示自然底数后面是否有数字，那么我们分别来看各种情况：

- 空格： 我们需要排除的情况是，当前位置是空格而后面一位不为空格，但是之前有数字，小数点，自然底数或者符号出现时返回false。

- 符号：符号前面如果有字符的话必须是空格或者是自然底数，标记sign为true。

- 数字：标记num和numAfterE为true。

- 小数点：如果之前出现过小数点或者自然底数，返回false，否则标记dot为true。

- 自然底数：如果之前出现过自然底数或者之前从未出现过数字，返回false，否则标记exp为true，numAfterE为false。

- 其他字符：返回false。

最后返回num && numAfterE即可。
Credit By GrandYang
https://www.cnblogs.com/grandyang/p/4084408.html
*/

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool num = false, numAfterE = true, Dot = false, Exp = false, Sign = false;
        for ( int i = 0; i < n; ++i )
        {
          if ( s[i] == ' ' )
          {
            if ( i < n - 1 && s[i + 1] != s[i] && ( Dot || Exp || Sign || num ) ) return false;
          }
          else if ( s[i] == '+' || s[i] == '-' )
          {
            if ( i > 0 && s[i - 1] != ' ' && s[i - 1] != 'e' ) return false;
            Sign = true;
          }
          else if ( s[i] == '.' )
          {
            if ( Dot || Exp ) return false;
            Dot = true;
          }
          else if ( s[i] == 'e' )
          {
            if ( !num || Exp ) return false;
            Exp = true;
            numAfterE = false;
          }
          else if ( s[i] >= '0' && s[i] <= '9' )
          {
            num = true;
            if ( Exp ) numAfterE = true;
          }
          else return false;
        }
        return num && numAfterE;
    }
};
