/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5


Start from the back to the front, consider the cornercase.
1. empty string, return 0
2. string likes "   " return 0
3. string start with " " likes "a acsad " get rid of the space

Below is the code */

class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        int size = s.length() - 1;
        //Count from back to front, initialize count to the last char
        int count = 0;
        //compare from back, if find the first " ", return
        //Or return the value of the whole length
        char c = s[size];
        //Get rid of white space
        while( c == ' ' )
        {
            size--;
            if( size < 0 ) return 0;
            c = s[size];
        }
        
        for ( int i = size; i >= 0; --i )
        {
            c = s[i];            
            if ( c == ' ' ) return count;
            count++;
        }
        return count;
    }
};
