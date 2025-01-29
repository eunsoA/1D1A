def solution(a, d, included):
    count = 0
    for i in range(len(included)):
        count += (a+d*i) * int(included[i])
    return count