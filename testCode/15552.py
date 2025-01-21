import sys
input = sys.stdin.read
output = sys.stdout.write

# 입력 받기
data = input().splitlines()

# 첫 번째 줄은 테스트 케이스 개수 T
T = int(data[0])

# 결과 계산 및 출력
results = []
for i in range(1, T + 1):
    A, B = map(int, data[i].split())
    results.append(A + B)

# 출력
output("\n".join(map(str, results)) + "\n")
