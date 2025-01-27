def solution(my_string, overwrite_string, s):
    return f"{my_string[:s]}{overwrite_string}{my_string[s+len(overwrite_string):]}"