import sys

N, M = map(int, sys.stdin.readline().split())

S = {sys.stdin.readline().strip() for _ in range(N)}

count = sum(1 for _ in range(M) if sys.stdin.readline().strip() in S)

print(count)