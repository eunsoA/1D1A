import sys

data = sys.stdin.read().strip().splitlines()

for i in range(15):
    for j in range(len(data)):  # 모든 행을 돌면서
        if i < len(data[j]):  # 현재 행의 i번째 문자가 존재하면 출력
            print(data[j][i], end='')
print()