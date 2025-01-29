def solution(num_list):
    count = 1
    for i in num_list :
        count*=i
    return int(count < sum(num_list)**2)