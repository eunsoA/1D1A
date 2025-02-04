def solution(arr, n):
    if len(arr) % 2 : # odd
        for i in range(len(arr)):
            if i%2==0 :
                arr[i] += n
        # arr[::2] += n
    else : # even
        for i in range(len(arr)):
            if i%2==1 :
                arr[i] += n
        # arr[1::2] += n
    return arr