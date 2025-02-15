import sys

A, B = sys.stdin.readline().split()

minChange = len(A)

for i in range(len(B)-len(A)+1):
    diff = 0

    for j in range(len(A)):
        if A[j] != B[i+j]:
            diff+=1
    
    minChange = min(minChange, diff)

print(minChange)