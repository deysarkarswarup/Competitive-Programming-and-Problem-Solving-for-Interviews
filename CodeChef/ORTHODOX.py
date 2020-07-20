#OR-thodox Distinction Problem Code: ORTHODOX
You are given an integer sequence A1,A2,…,AN. For any pair of integers (l,r) such that 1≤l≤r≤N, let's define OR(l,r) as Al∨Al+1∨…∨Ar. Here, ∨ is the bitwise OR operator.

# In total, there are N(N+1)2 possible pairs (l,r), i.e. N(N+1)2 possible values of OR(l,r). Determine if all these values are pairwise distinct.

# Input
# The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
# The first line of each test case contains a single integer N.
# The second line contains N space-separated integers A1,A2,…,AN.
# Output
# For each test case, print a single line containing the string "YES" if all values of OR(l,r) are pairwise distinct or "NO" otherwise (without quotes).

# Constraints
# 1≤T≤300
# 1≤N≤105
# 0≤Ai≤1018 for each valid i
# the sum of N over all test cases does not exceed 3⋅105
# Example Input
# 4
# 3
# 1 2 7
# 2
# 1 2
# 3
# 6 5 8
# 5
# 12 32 45 23 47
# Example Output
# NO
# YES
# YES
# NO
# Explanation
# Example case 1: The values of OR(l,r) are 1,2,7,3,7,7 (corresponding to the contiguous subsequences [1],[2],[7],[1,2],[2,7],[1,2,7] respectively). We can see that these values are not pairwise distinct.

# Example case 2: The values of OR(l,r) are 1,2,3 (corresponding to the contiguous subsequences [1],[2],[1,2] respectively) and they are pairwise distinct.
# cook your dish here
def subarrayBitwiseOR(A): 
    # res contains distinct values 
    res = set() 
    pre = {0} 
    for x in A: 
        pre = {x | y for y in pre} | {x} 
        res |= pre 
    return len(res) 
    
t=int(input())
for _ in range(t):
    lst = []
    n = int(input()) 
    lst=list(map(int,input().split()))
    distor=subarrayBitwiseOR(lst)
    if (distor == n*(n+1)/2):
        print("YES")
    else:
        print("NO")
