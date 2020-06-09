/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?


This solution is already optimized, using dynamic allocation, only need one previous vector, reduce space usage
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp;
        vector<int> curr;
        temp.push_back( 1 );
        curr.push_back( 1 );
        for ( int i = 1; i <= rowIndex; i++ )
        {
            curr.resize( i + 1, 1 );
            for ( int j = 1; j < i; j++ )
            {
                curr[j] = temp[j - 1] + temp[j];
            }
            temp = curr;
        }
        return curr;
    }
};
