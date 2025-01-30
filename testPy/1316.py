def is_group_word(word):
    seen = set() # 이미 등장한 문자를 기록
    prev_char = ''  # 이전 문자를 저장

    for char in word:
        if char != prev_char:   # 문자가 연속되지 않을 경우
            if char in seen: # 이미 등장한 문자면 그룹 단어가 아님
                return False
            seen.add(char) # 새로 등장한 문자 기록
        prev_char = char  # 현재 문자를 이전 문자로 업데이트
    return True

import sys
input = sys.stdin.read
data = input().splitlines()

n = int(data[0])
words = data[1:]

count = 0
for word in words :
    if is_group_word(word):
        count += 1 

print(count)