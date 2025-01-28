def solution(number, n, m):
    answer = 0
    return int(not(number%n) and not(number%m))