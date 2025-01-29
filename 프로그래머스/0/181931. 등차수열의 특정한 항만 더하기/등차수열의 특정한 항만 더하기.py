def solution(a, d, included):
    count = 0
    for i in range(len(included)):
        if included[i] :
            count += a+d*i
    return count