import sys

N, M = sys.stdin.readline().strip().split(' ')

S = list()
T = list()
for i in range(int(N)):
    S.append(sys.stdin.readline().strip())

for j in range(int(M)):
    T.append(sys.stdin.readline().strip())

count = 0
for word in T:
    if word in S :
        count += 1

print(count)