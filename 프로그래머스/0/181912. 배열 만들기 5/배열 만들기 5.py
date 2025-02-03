def solution(intStrs, k, s, l):
    answer = []
    for myStr in intStrs :
        if int(myStr[s:s+l:]) > k :
            answer.append(int(myStr[s:s+l:]))
    return answer