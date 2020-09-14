// Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

// Note:

// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Example 1:

// Input: [2,2,3,2]
// Output: 3
// Example 2:

// Input: [0,1,0,1,0,1,99]
// Output: 99

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long int sum1=0, sum2=0;
         for(int i=0;i<nums.size();i++)
         {
            sum1 = sum1 + nums[i];
         }
         set<int>s;
         for(int i=0;i<nums.size();i++)
         {
             s.insert(nums[i]);
         }
         set <int> :: iterator itr; 
         for (itr = s.begin(); itr != s.end(); itr++) 
         { 
             sum2=sum2+*itr; 
          }
          int result=(sum2*3-sum1)/2;

         return result;
    }
};
