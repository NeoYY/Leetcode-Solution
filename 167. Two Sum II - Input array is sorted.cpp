/*

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.


Solution one using hash map
Solution two use two pointer
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        unordered_map<int, int> hash;
        for ( int i = 0; i < numbers.size(); ++i )
        {
            int find_num = target - numbers[i];
            if ( hash.find( find_num ) != hash.end() )
            {
                res.push_back( hash.find( find_num )->second + 1 );
                res.push_back( i + 1 );
                return res;
            }
            hash.insert( make_pair(numbers[i], i) );
        }
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2);
        int a = 0;
        int b = numbers.size() - 1;
        while ( a < b )
        {
            if ( numbers[a] + numbers[b] == target )
            {
                res[0] = a + 1;
                res[1] = b + 1;
                return res;
            }
            else if ( numbers[a] + numbers[b] < target ) a++;
            else b--;
        }
        return res;
    }
};
