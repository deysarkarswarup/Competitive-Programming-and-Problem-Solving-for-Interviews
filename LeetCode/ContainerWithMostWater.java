Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

// Example:

// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49

class Solution {
    public int maxArea(int[] height) {
        int len = height.length;
        int totalheight, waterheight, maxheight = 0;
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                waterheight = Math.min(height[i],height[j]);
                totalheight= waterheight * (j-i);
                maxheight = Math.max(maxheight,totalheight);
                
            }
        }
        return maxheight;
        
    }
}
