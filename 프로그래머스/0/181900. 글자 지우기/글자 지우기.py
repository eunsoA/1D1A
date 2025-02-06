def solution(my_string, indices):
    str_list = list(my_string)
    for i in indices : 
        str_list[i] = '_'
    return ''.join([c for c in str_list if c != '_'])