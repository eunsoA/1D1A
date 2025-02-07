def solution(arr):
    try :
        min = arr.index(2, 0)
        max = arr[::-1].index(2, 0)
        return arr[min:len(arr)-max] if min != len(arr)-max else [arr[min]]
    except :
        return [-1]