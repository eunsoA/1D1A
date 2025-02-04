def solution(my_strings, parts):
    answer = ''
    for i in range(len(my_strings)):
        s, e = parts[i]
        mystr = my_strings[i]
        answer += mystr[s:e+1]
    return answer