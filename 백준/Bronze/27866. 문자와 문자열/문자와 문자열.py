import sys
data = sys.stdin.read().splitlines()
print(data[0].strip()[int(data[1])-1])