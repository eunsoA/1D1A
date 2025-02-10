import sys

n, m = map(int, sys.stdin.readline().split())

nArr = {sys.stdin.readline().strip() for _ in range(n)}
mArr = {sys.stdin.readline().strip() for _ in range(m)}

nmArr = sorted(nArr & mArr)
print(len(nmArr))
print("\n".join(nmArr))