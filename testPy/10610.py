import sys

word = sys.stdin.readline().strip()

wordList = [word]
for i in range(1, len(word)):
    wordList += [word[j:j+i] for j in range(len(word)) if j+i<=len(word)]

print(len(set(wordList)))