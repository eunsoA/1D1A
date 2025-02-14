import sys

word = sys.stdin.readline().strip()

count = [0] * 26

for char in word:
    count[ord(char)-ord('a')] += 1

print(' '.join(map(str, count)))