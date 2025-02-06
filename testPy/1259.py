import sys

data = sys.stdin.read().strip().split('\n')

for line in data:
    if line == '0' : continue
    print('yes') if line == line[::-1] else print('no')