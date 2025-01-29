def solution(num_list):
    odd = ''.join(str(num) for num in num_list if num%2)
    even = ''.join(str(num) for num in num_list if not(num%2))
    return int(odd) + int(even)