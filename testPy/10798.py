import sys

data = sys.stdin.read().strip().splitlines()

for i in range(15):
    print(data[0][i], end='') if data[0][i] else None
    print(data[1][i], end='') if data[1][i] else None
    print(data[2][i], end='') if data[2][i] else None
    print(data[3][i], end='') if data[3][i] else None
    print(data[4][i], end='') if data[4][i] else None