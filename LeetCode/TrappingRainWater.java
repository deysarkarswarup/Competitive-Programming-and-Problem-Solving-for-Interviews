Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

// Example:

// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

class Solution {
    public int trap(int[] height) {
        int len = height.length;
        int sum=0;
        int [] left = new int[len];
        int [] right = new int[len];
        if(len==0){
            return 0;
        }
        else{
        left[0]=height[0];
        int a=height[len-1];
        right[len-1]=a;
        
        for(int i=1;i<len;i++)
        {          
            if(height[i]>left[i-1])
            {
                left[i]=height[i];
            }
            else{
                left[i]=left[i-1];
            }
        }
        // for(int i=0;i<len;i++)
        // {
        //     System.out.println(left[i]);
        // }
        for(int i=len-2;i>=0;i--)
        {
            if(height[i]>right[i+1])
            {
                right[i]=height[i];
            }
            else
            {
                right[i]=right[i+1];
            }
        }
        //   for(int i=0;i<len;i++)
        // {
        //     System.out.println(right[i]);
        // }
        
        for(int i=0;i<len;i++)
        { 
            sum = sum + Math.min(left[i],right[i])-height[i];
        }
        }
        return sum;
        
    }
}

// left = 0,1,1,2,2,2,2,3,3,3,3,3
// right =3,3,3,3,3,3,3,3,2,2,2,1                         

// sum = 0
// sum+=min(left[i],right[i])-height[i]
