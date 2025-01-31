def solution(l, r):
    answer = [i for i in range(l,r+1) if set(str(i)) <= {'0','5'}]
    return answer if answer else [-1]