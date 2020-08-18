#Smallest KMP Problem Code: SKMP

Chef has a string S. He also has another string P, called pattern. He wants to find the pattern in S, but that might be impossible. Therefore, he is willing to reorder the characters of S in such a way that P occurs in the resulting string (an anagram of S) as a substring.

# Since this problem was too hard for Chef, he decided to ask you, his genius friend, for help. Can you find the lexicographically smallest anagram of S that contains P as substring?

# Note: A string B is a substring of a string A if B can be obtained from A by deleting several (possibly none or all) characters from the beginning and several (possibly none or all) characters from the end.

# Input
# The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
# The first line of each test case contains a single string S.
# The second line contains a single string P.
# Output
# For each test case, print a single line containing one string ― the smallest anagram of S that contains P.

# Constraints
# 1≤T≤10
# 1≤|P|≤|S|≤105
# S and P contain only lowercase English letters
# there is at least one anagram of S that contains P
# Subtasks
# Subtask #1 (20 points): |S|≤1,000
# Subtask #2 (80 points): |S|≤105
# Example Input
# 3
# akramkeeanany
# aka
# supahotboy
# bohoty
# daehabshatorawy
# badawy
# Example Output
# aaakaeekmnnry
# abohotypsu
# aabadawyehhorst

# cook your dish here
t = int(input())
for _ in range(t):
    string = list(input())
    pattern = input()
    p = pattern
    pattern = list(pattern)
    for i in pattern:
        string.remove(i)
    string.sort()
    l=[]
    s=''
    if pattern[0] in string:
        for i in range (len(string)):
            if(string[i]==pattern[0]):
                s = s+string[i]
                string[i]=''
        l.append(p)
        l.append(s)
        l2=sorted(l)
        l1=''.join(str(i) for i in l)
        l2=''.join(str(i) for i in l2)
        string.append(min(l1,l2))
        string.sort()
        print(''.join(str(i) for i in string))
    else:
        c=0
        for i in range (len(string)):
            ascii_string = ord(string[i])
            ascii_pattern = ord(pattern[0])
            if(ascii_string > ascii_pattern):
                string.insert(i,p)
                c=c+1
                break
        if(c==0):
            string.insert(len(string),p)
        print(''.join(str(i) for i in string))
