# 입력 받기
A = int(input())
B = int(input())
C = int(input())

# 세 수의 곱 계산
result = A * B * C

# 숫자 개수 세기
for i in range(10):
    print(str(result).count(str(i)))  # 0부터 9까지 등장 횟수 출력
