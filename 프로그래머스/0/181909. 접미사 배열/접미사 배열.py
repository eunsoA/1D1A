def solution(my_string):
    return sorted([my_string[len(my_string)-i-1::] for i in range(len(my_string))])