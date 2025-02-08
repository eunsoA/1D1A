def solution(str_list, ex):
    return ''.join(c if ex not in c else '' for c in str_list)