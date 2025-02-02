import sys

# 입력 받기
data = sys.stdin.read().splitlines()

T = int(data[0])

result = []
for i in range(1,T+1):
    score = 0
    count = 0
    for c in data[i]:
        if c == 'O':
            count += 1
            score += count
        else : 
            count = 0
    result.append(str(score))

print('\n'.join(result))