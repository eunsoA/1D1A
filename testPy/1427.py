import sys

word = sys.stdin.readline().strip()

print(''.join(sorted([c for c in word],reverse=True)))