def solution(x) :
    answer = [x]
    while(x!=1) :
        if x%2: # odd
            x = 3*x +1
        else :
            x //= 2
        answer.append(x)
    return answer