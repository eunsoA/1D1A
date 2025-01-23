# 주사위 3개의 값을 입력받기
a, b, c = map(int, input().split())

# 조건에 따라 상금 계산
if a == b == c:
    # 세 숫자가 모두 같은 경우
    reward = 10000 + a * 1000
elif a == b or a == c:
    # 두 숫자가 같은 경우 1
    reward = 1000 + a * 100
elif b == c:
    # 두 숫자가 같은 경우 2
    reward = 1000 + b * 100
else:
    # 모두 다른 경우
    reward = max(a, b, c) * 100

# 결과 출력
print(reward)
