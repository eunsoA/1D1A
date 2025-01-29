def solution(num_list):
    count = 1
    for i in num_list :
        count*=i
    return 1 if bool(count < sum(num_list)**2) else 0