import sys

myStr = sys.stdin.readline().strip()

suffix = [myStr[i:] for i in range(len(myStr))]

print('\n'.join(sorted(suffix)))