/*

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.



Example 1:

Input: num = 16
Output: true
Example 2:

Input: num = 14
Output: false


Constraints:

1 <= num <= 2^31 - 1

Solution using binary search
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 0, j = num;
        if ( num == 1 ) return true;
        while ( i < j )
        {
            int mid = i + ( j - i ) / 2;
            if ( mid < num / mid )
            {
                i = mid + 1;
            }
            else if ( mid > num / mid )
            {
                j = mid;
            }
            else
            {
                return mid * mid == num ? true : false;
            }
        }
        return false;
    }

};
