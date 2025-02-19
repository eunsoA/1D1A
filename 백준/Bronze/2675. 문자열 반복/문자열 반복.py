import sys

T = int(sys.stdin.readline().strip())
while (T>0):
    R, S = sys.stdin.readline().strip().split()
    R = int(R)
    print(''.join([s*R for s in S]))
    T -= 1