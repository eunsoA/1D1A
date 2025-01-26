def solution(num_str):
    answer = int(num_str)
    result = 0
    while answer > 0 :
        result += answer%10
        answer //= 10
    return result