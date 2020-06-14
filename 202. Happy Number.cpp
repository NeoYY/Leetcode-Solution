/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example:

Input: 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

//Solution using unordered_map, set, unordered_map can also do this

class Solution {
private:
    vector<int> square = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };
public:
    bool isHappy(int n) {
        unordered_map<int, int> temp;
        while ( n != 1 )
        {
            int res = 0;
            while ( n )
            {
                res += square[n % 10];
                n = n / 10;
            }
            temp[res]++;
            if ( temp[res] > 1 ) return false;
            n = res;
        }
        return true;
    }
};
