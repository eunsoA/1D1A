def solution(arr, query):
    for idx, q in enumerate(query):
        if idx%2 : # odd
            arr = arr[q:]
        else : # even
            arr = arr[:q+1]
    return arr