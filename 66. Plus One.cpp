/* Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

Basically, we consider the corner case first, then normally compute
1. input [0], output [1]
2. input [9,9,9...,9], output[1,0,0,0,...,0]

Below is the code */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size() - 1;
        int count = 1;
        //corner case, [0], return[1]
        if ( digits[size] == 0 && size == 0 )
        {
            digits[size] = 1;
            return digits;
        }
        //count from the back, use count as the carry bit
        for ( int i = size; i >= 0; --i )
        {
            //when no carry bit, compute end, continue
            if ( count == 0 ) continue;
            else
            {
                //when carry bit = 1 and the number = 9, set the number to 0
                //save the carry bit
                if( digits[i] == 9 )
                {
                    digits[i] = 0;
                    count = 1;
                }
                //if the last computing digit is not 9
                //add one and end
                else
                {
                    digits[i]++;
                    count = 0;
                }
            }
        }
        //ensure it is not overflow, if not, return 
        if( count == 0 ) return digits;
        //if overflow, add one digit at the end
        //only possible case is like [1,0,0,0]
        //so set the first one 1, and others 0
        digits.push_back( 0 );
        digits[0] = 1;
        for( int i = 1; i <= size; ++i )
        {
            digits[i] = 0;
        }
        return digits;
    }
};

