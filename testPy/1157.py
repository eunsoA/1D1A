import sys
from collections import Counter

word = input().upper()
count = Counter(word) # 각 문자의 빈도수 계산

most_common = count.most_common() # 빈도수 내림차순 정렬된 리스트 반환
max_count = most_common[0][1]  # 최빈값의 등장 횟수

# 최빈값을 가진 문자 찾기
most_frequent_letters = [char for char, count in most_common if count == max_count]

# 최빈값을 가진 문자가 여러 개면 '?' 출력
if len(most_frequent_letters) > 1:
    print('?')
else :
    print(most_frequent_letters[0])