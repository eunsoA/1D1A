def solution(q, r, code):
    answer = ''
    for i in range(len(code)) :
        if i % int(q) == int(r) :
            answer += code[i]
    return answer