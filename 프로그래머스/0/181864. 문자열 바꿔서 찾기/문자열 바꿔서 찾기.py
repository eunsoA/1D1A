def solution(myString, pat):
    return int(pat in myString.replace('A','K').replace('B','A').replace('K','B'))