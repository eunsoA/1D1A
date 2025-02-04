def solution(arr, n):
    N = len(arr)
    if N % 2 : # odd
        for i in range(0,N,2): arr[i] += n
    else : # even
        for i in range(1,N,2): arr[i] += n
    return arr