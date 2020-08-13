#Chefina and Swaps Problem Code: CHFNSWPS
Chefina has two sequences A1,A2,…,AN and B1,B2,…,BN. She views two sequences with length N as identical if, after they are sorted in non-decreasing order, the i-th element of one sequence is equal to the i-th element of the other sequence for each i (1≤i≤N).

# To impress Chefina, Chef wants to make the sequences identical. He may perform the following operation zero or more times: choose two integers i and j (1≤i,j≤N) and swap Ai with Bj. The cost of each such operation is min(Ai,Bj).

# You have to find the minimum total cost with which Chef can make the two sequences identical.

# Input
# The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
# The first line of each test case contains a single integer N.
# The second line contains N space-separated integers A1,A2,…,AN.
# The third line contains N space-separated integers B1,B2,…,BN.
# Output
# For each test case, print a single line containing one integer ― the minimum cost, or −1 if no valid sequence of operations exists.

# Constraints
# 1≤T≤2,000
# 1≤N≤2⋅105
# 1≤Ai,Bi≤109 for each valid i
# the sum of N over all test cases does not exceed 2⋅106
# Subtasks
# Subtask #1 (15 points):

# T≤20
# N≤20
# Subtask #2 (85 points): original constraints

# Example Input
# 3
# 1
# 1
# 2
# 2
# 1 2
# 2 1
# 2
# 1 1
# 2 2
# Example Output
# -1
# 0
# 1
# Explanation
# Example case 1: There is no way to make the sequences identical, so the answer is −1.

# Example case 2: The sequence are identical initially, so the answer is 0.

# Example case 3: We can swap A1 with B2, which makes the two sequences identical, so the answer is 1.

#Solution
# cook your dish here
test = int(input())
for _ in range(test):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    flag = True
    min = 2147483647
    elements = set()
    A,B=[],[]
    lenA, lenB = 0,0
    freq1, freq2 = {}, {}
    for i in a:
        if (i in freq1):
            freq1[i]=freq1[i]+1
        else:
            freq1[i]=1
            freq2[i]=0
            elements.add(i)
    for i in b:
        if (i in freq2):
            freq2[i]=freq2[i]+1
        else:
            freq2[i]=1
            if i not in elements:
                freq1[i]=0
                elements.add(i)
    for i in elements:
        count1 = freq1[i]
        count2 = freq2[i]
        freq = count1 + count2
        if((count1 + count2) != ((freq >> 1) << 1)):
            flag = False
            break
        if(min > i):
            min = i
        if(count1 < count2):
            for j in range((count2 - count1) >> 1):
                B.append(i)
                lenB=lenB+1
        elif(count2 < count1):
            for j in range((count1 - count2) >> 1):
                A.append(i)
                lenA=lenA+1
    if(lenA != lenB):
        flag = False
    if(flag!=True):
        print(-1)
        continue
    A.sort()
    B.sort()
    min= min*2
    lessMinA,lessMinB=0,0
    for i in A:
        if i > min:
            break
        lessMinA=lessMinA+1
    greatMinA = lenA - lessMinA
    for i in B:
        if i > min:
            break
        lessMinB=lessMinB+1
    greatMinB =lenB-lessMinB
    cost = 0
    if(lessMinA <= greatMinB):
        for i in A[:lessMinA]:
            cost=cost+i
        for i in B[:lessMinB]:
            cost=cost+i
        cost=cost+(min * (greatMinA - lessMinB))
    else:
        for i in A[:(greatMinB)]:
            cost=cost+i
        for i in B[:(greatMinA)]:
            cost=cost+i
        i=greatMinB
        j=greatMinA
        for k in range(lessMinB - greatMinA):
            if(A[i] < B[j]):
                cost=cost+A[i]
                i=i+1
            else:
                cost=cost+B[j]
                j=j+1
    print(cost)










