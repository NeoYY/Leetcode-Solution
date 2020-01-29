/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.


**Below are the codes
*/


//Method 1, creating new vector, return the maxi_sum via iterator, space usage high( Dynamic Programming )
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Create a new array to store the sum
        vector<int> temp;
        temp.push_back( nums[0] );
        for( int i = 1; i < nums.size(); ++i ) {
            //If the previous sum is less then 0, directly push back new nums
            if( temp[i-1] < 0 ) temp.push_back( nums[i] );
            else {
                temp.push_back( temp[i-1] + nums[i] );
            }
        }
        //return the maximum element using iterator
        return *max_element( temp.begin(), temp.end() );
    }
};

//Method 2, no need for new vector
class Solution{
  public: int maxSubArray( vector<int>& nums ) 
  {
      int global_max = INT_MIN;
      int local_max = 0;
      //Travase the whole array and if find a bigger local_sum than replace the  global one
      for ( int i = 0; i < nums.size(); ++i ) 
      {
          //In this case, if local_max is nega it will be nums[i],
          //Otherwise it will be the sum
          local_max += nums[i];
          //Compare the sum
          if ( global_max < local_max )
          {
              global_max = local_max;
          }
          //Reset the counter
          if ( local_max < 0 )
          {
              local_max = 0;
          }
      }
      return global_max;
  }  
};
