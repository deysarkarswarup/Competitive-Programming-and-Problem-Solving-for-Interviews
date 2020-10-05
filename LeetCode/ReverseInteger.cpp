// 7. Reverse Integer

// Given a 32-bit signed integer, reverse digits of an integer.

// Note:
// Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

 

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
// Example 4:

// Input: x = 0
// Output: 0
 

// Constraints:

// -231 <= x <= 231 - 1

class Solution {
public:
    int reverse(int x) {
        long long int rev = 0, rem;
        while(x != 0) {
        rem = x%10;
        rev = rev*10 + rem;
        x /= 10;
    }
        if (rev < INT_MIN || rev > INT_MAX) {
            return 0;
        }
        else
            return rev;
    }
};
