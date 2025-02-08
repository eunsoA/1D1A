def solution(numbers, n):
    numSum = 0
    for i in numbers:
        numSum += i
        if numSum > n : return numSum