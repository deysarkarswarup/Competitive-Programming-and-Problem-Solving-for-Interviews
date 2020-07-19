#Even-tual Reduction Problem Code: EVENTUAL

#You are given a string S with length N. You may perform the following operation any number of times: choose a non-empty substring of S (possibly the whole string S) such that each character occurs an even number of times in this substring and erase this substring from S. (The parts of S before and after the erased substring are concatenated and the next operation is performed on this shorter string.)

# For example, from the string "acabbad", we can erase the highlighted substring "abba", since each character occurs an even number of times in this substring. After this operation, the remaining string is "acd".

# Is it possible to erase the whole string using one or more operations?

# Note: A string B is a substring of a string A if B can be obtained from A by deleting several (possibly none or all) characters from the beginning and several (possibly none or all) characters from the end.

# Input
# The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
# The first line of each test case contains a single integer N.
# The second line contains a single string S with length N.
# Output
# For each test case, print a single line containing the string "YES" if it is possible to erase the whole string or "NO" otherwise (without quotes).

# Constraints
# 1≤T≤200
# 1≤N≤1,000
# S contains only lowercase English letters
# Example Input
# 4
# 6
# cabbac
# 7
# acabbad
# 18
# fbedfcbdaebaaceeba
# 21
# yourcrushlovesyouback
# Example Output
# YES
# NO
# YES
# NO
# Explanation
# Example case 1: We can perform two operations: erase the substring "abba", which leaves us with the string "cc", and then erase "cc"
#Solution:-
# cook your dish here
try:
    t=int(input())
    for _ in range(t):
        n=input()
        s=input()
        flag='YES'
        freq =[0]*26
        n = len(s) 
        for i in range(n):
            freq[ord(s[i])-97]+= 1
        for i in range(26): 
            if (freq[i]% 2 == 1):
                flag='NO'
                break
        print(flag)
        
except:
    pass






