def solution(my_string, queries):
    mylist = list(my_string)
    for s,e in queries :
        mylist[s:e+1] = mylist[s:e+1][::-1]
    return ''.join(mylist)