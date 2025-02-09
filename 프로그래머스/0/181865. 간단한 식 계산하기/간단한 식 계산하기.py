def solution(binomial):
    arr = binomial.strip().split()
    if arr[1] == '+':
        return int(arr[0])+int(arr[2])
    elif arr[1] == '-':
        return int(arr[0])-int(arr[2])
    elif arr[1]=='*':
        return int(arr[0])*int(arr[2])