# N과 X 입력받기
N, X = map(int, input().split())

# 배열 입력받기
arr = list(map(int, input().split()))

# X보다 작은 수 출력
for num in arr:
    if num < X:
        print(num, end=" ")