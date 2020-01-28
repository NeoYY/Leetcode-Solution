/*#The count-and-say sequence is the sequence of integers with the first five terms as following:#

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.

**Basically, the next output the the count of the previous input**
*Belowed are the code*/

class Solution {
public:
    string countAndSay( int n ) {
    //manually initialize the first output
        string res = "1";
        int i = 1;      
        //i will be used to track the finally result
        while( i < n ) {
        string temp = "";            
        int count = 0;
        char c = res[0];
        //j will be used to track the traverse of the current layer
            for( int j = 0; j <= res.length(); j++ ) {
            //when the search not end and the value are the same, increment count
                if( j!= res.length() && res[j] == c ) {
                    count++;
                }
                //this means the current number is ended, will add to the temp,
                //and work on the next one
                else {
                    temp += to_string( count ) + c;
                    if( j != res.length() ) {
                        c = res[j];
                        count = 1;                        
                    }
                }
            }
            res = temp;
            i++;
        }
        return res;
    }
};

