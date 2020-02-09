/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned

The only thing need to be noticed is the situation of corner case. If use i^2 <= x && (i+1)^2 > x may overflow so use division.
The first approach is brute search, second is binary search

Below are the codes*/


//Approach one, brute search
class Solution {
public:
    int mySqrt(int x) {
        if ( x == 0 )
        {
            return 0;
        }
        //search from 1 to x
        for ( int i = 1; i <= x; ++i )
        {
        //Use division instead of multiplx to avoid overflow
            if ( ( i <= x / i ) && ( ( i + 1 ) > x / ( i + 1 ) ) )
                {
                    return i;
                }
        }
        //error message
        return -1;
    }
};

//Approach 2, binary search
class Solution {
public:
    int mySqrt(int x) {
    //Corner case, input is 0
        if ( x == 0 )
        {
            return 0;
        }
        return mySqrt_h( 0, x, x );
    }
private:
    int mySqrt_h( int low, int high, int x )
{
    //Corner case, input = 1
    if ( high - low == 1 ) return 1;
    int mid = low + ( high - low ) / 2;
    //If satisfy the case, mid is the value that needed
    if ( ( mid <= x / mid ) && ( ( mid + 1 ) > x / ( mid + 1 ) ) )
    {
        return mid;
    }
    //If large, choose lower partition
    //If small, choose higher partition.
    else
    {
        if ( mid < x / mid )
        {
            return mySqrt_h( mid, high, x );
        }
        else
        {
            return mySqrt_h( low, mid, x );
        }
    }
}
};
