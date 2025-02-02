import sys
data = sys.stdin.read().splitlines()
string = data[0].strip()
count = int(data[1])-1

print(string[count])