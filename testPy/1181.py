import sys
N = int(sys.stdin.readline().strip())
words = set()

for _ in range(N):
    words.add(sys.stdin.readline().strip())

words = sorted(words, key=lambda x: (len(x), x))

for word in words:
    print(word)