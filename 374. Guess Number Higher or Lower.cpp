/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example :

Input: n = 10, pick = 6
Output: 6

Binary Search

Solution one recursive
two in one loop
*/

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int ans = Search(1, n);
        return ans;
    }
    int Search(int low, int high)
    {
        int mid = low + (high - low) / 2;
        if (guess(mid) == -1) return Search(low, mid - 1);
        if (guess(mid) == 1) return Search(mid + 1, high);

        return mid;
    }
};

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (guess(mid) == -1) high = mid - 1;
            if (guess(mid) == 1) low = mid + 1;
            if (guess(mid) == 0) return mid;
        }
        return low;
    }
