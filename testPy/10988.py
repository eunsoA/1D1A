import sys
my_string = sys.stdin.read().strip()

if my_string[::-1] == my_string:
    print(1)
else:
    print(0)