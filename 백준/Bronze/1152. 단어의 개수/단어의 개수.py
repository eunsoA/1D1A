import sys

# 입력 받기
sentence = sys.stdin.readline().strip()

# 공백 기준으로 나누기
words = sentence.split()

# 단어 개수 출력
print(len(words))