def solution(arr, flag):
    answer = []
    for i,f in zip(arr,flag):
        if f:
            answer += [i] * i * 2
        else :
            answer = answer[:-i] 
    return answer