import math
def solution(num_list):
    return sum(num_list) if len(num_list)>=11 else math.prod(num_list)