import sys

docs = sys.stdin.readline().strip()
word = sys.stdin.readline().strip()

count = 0
i=0
while i <= len(docs)-len(word) :
    if docs[i:i+len(word)] == word :
        count += 1
        i += len(word)
    else:
        i += 1

print(count)