def solution(arr):
    row_count = len(arr)
    col_count = len(arr[0])
    
    if row_count > col_count:
        for i in range(len(arr)):
            arr[i] += [0] * (row_count - col_count)
    elif row_count < col_count:
        arr += [[0] * col_count]*(col_count - row_count)
    
    return arr