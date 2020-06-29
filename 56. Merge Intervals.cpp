/*

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

Solution will need to use sort
Solution two do inserting without sorting, but slower
*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if ( intervals.empty() ) return {};
        vector<vector<int>> res;
        sort( intervals.begin(), intervals.end() );
        int left = intervals[0][0], right = intervals[0][1];
        for ( int i = 1; i < intervals.size(); ++i )
        {
            if ( right >= intervals[i][0] && right <= intervals[i][1] )
            {
                right = intervals[i][1];
            }
            else if ( right >= intervals[i][1] )
            {
                continue;
            }
            else
            {
                res.push_back( { left, right } );
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        res.push_back( { left, right } );
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if ( intervals.empty() ) return {};
        vector<vector<int>> res;
        int n = intervals.size();
        for ( int i = 0; i < n; ++i )
        {
            res = insert( res, intervals[i] );
        }
        return res;
    }
private:
    vector<vector<int>> insert( vector<vector<int>>& interval, vector<int>& new_interval )
    {
        vector<vector<int>> res;
        int ct = 0, n = interval.size();
        for ( int i = 0; i < n; ++i )
        {
            if ( interval[i][1] < new_interval[0] )
            {
                res.push_back( interval[i] );
                ++ct;
            }
            else if ( interval[i][0] > new_interval[1] )
            {
                res.push_back( interval[i] );
            }
            else
            {
                new_interval[0] = min( interval[i][0], new_interval[0] );
                new_interval[1] = max( interval[i][1], new_interval[1] );
            }
        }
        res.insert( res.begin() + ct, new_interval );
        return res;
    }
};
