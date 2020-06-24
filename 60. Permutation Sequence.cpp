/*

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"


Solution follows the formula:
a1 = k / ( n - 1 )!
k1 = k % ( n - 1 )!
a2 = k1 / ( n - 2 )!
k2 = k1 % ( n - 2 )!
...
an - 1 = kn - 2 / 1!
kn - 1 = kn - 2 / 1!
an = kn - 1 / 0!
kn = kn - 1 % 0!

Credit to Grandyang
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        string s = "123456789";
        vector<int> num( n, 1 );
        for ( int i = 1; i < n; ++i )
        {
            num[i] = num[i - 1] * i;
        }
        --k;
        for ( int i = n; i >= 1 ; --i )
        {
            int j = k / num[i - 1];
            k %= num[i - 1];
            res = res + s[j];
            s.erase( j, 1 );
        }
        return res;
    }
};
