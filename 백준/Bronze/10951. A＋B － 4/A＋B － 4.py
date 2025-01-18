import sys

# 입력을 EOF까지 처리
for line in sys.stdin:
    A, B = map(int, line.split())
    print(A + B)
