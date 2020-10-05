// 9. Palindrome Number

// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

// Follow up: Could you solve it without converting the integer to a string?

 

// Example 1:

// Input: x = 121
// Output: true
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Example 4:

// Input: x = -101
// Output: false
 

// Constraints:

// -231 <= x <= 231 - 1

class Solution {
public:
    bool isPalindrome(int x) {
        long long int rev=0, rem, temp=x;
        if(x>=0)
        {
            while(x != 0)
            {
                rem = x%10;
                rev = rev*10 + rem;
                x /= 10;
            }
            if(temp == rev)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};
