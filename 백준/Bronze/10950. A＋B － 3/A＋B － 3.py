# 테스트 케이스 개수 입력
T = int(input())

# 각 테스트 케이스 처리
for _ in range(T):
    A, B = map(int, input().split())
    print(A + B)
