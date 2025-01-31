def solution(arr) :
    stk = []
    i = 0  # 인덱스 초기화
    while i < len(arr):  # 배열 크기보다 작을 때까지 반복
        if not stk :
            stk.append(arr[i])
            i+=1
        else :
            if stk[-1] < arr[i]:
                stk.append(arr[i])
                i += 1
            else : 
                stk.pop()            
    return stk