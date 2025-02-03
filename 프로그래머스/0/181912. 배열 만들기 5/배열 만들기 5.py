def solution(intStrs, k, s, l):
    return [int(myStr[s:s+l:]) for myStr in intStrs if int(myStr[s:s+l:])>k]