//Polygon Relationship Problem Code: POLYREL

// You are given a strictly convex polygon with N vertices (numbered 1 through N). For each valid i, the coordinates of the i-th vertex are (Xi,Yi). You may perform the following operation any number of times (including zero):

// Consider a parent polygon. Initially, this is the polygon you are given.
// Draw one of its child polygons ― a simple non-degenerate polygon such that each of its sides is a chord of the parent polygon (it cannot be a side of the parent polygon). The operation cannot be performed if the parent polygon does not have any child polygons.
// The child polygon which you drew becomes the new parent polygon.
// Your goal is to draw as many sides of polygons in total as possible (including the polygon given at the start). Find this maximum total number of sides.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains a single integer N.
// N lines follow. For each valid i, the i-th of these lines contains two space-separated integers Xi and Yi.
// Output
// Print a single line containing one integer ― the maximum possible number of sides of polygons.

// Constraints
// 1≤T≤1,000
// 3≤N≤105
// |Xi|,|Yi|≤109 for each valid i
// the sum of N over all test cases does not exceed 2⋅106
// Example Input
// 2
// 4
// -100 1
// 0 2
// 0 0
// 100 1
// 7
// -4 0
// -3 -2
// -3 2
// 0 -4
// 2 -3
// 2 3
// 3 2
// Example Output
// 4
// 10
// Explanation
// Example case 1: It is not possible to draw a child polygon.

// Example case 2: We can draw a child polygon once, e.g. with vertices (−3,−2), (−3,2) and (3,2). Even though there are several other ways to draw a child polygon, it can only be a triangle, so the total number of sides cannot exceed 7+3=10.

//Solution:

#include <stdio.h>

int main()
{
    int n,result,t,rem;
    scanf("%d",&t);
    for(int j = 0; j<t ; j++)
    {
        scanf("%d",&n);
        int x[n];
        int y[n];
        for(int i = 0; i<n; i++)
        {
            scanf("%d %d",&x[i],&y[i]);
        }
        if(n < 3)
        {
            result = 0;
        }
        
        else if(n >= 3 && n <= 5)
        {
            result = n;
        }
        else
        {
            result = n;
            rem = n/2;
            while(rem > 5)
            {
                result = result + rem;
                rem = rem / 2;
            }
            result = result + rem;
        }    
        printf("%d\n",result);
        
    }    

    return 0;
}
