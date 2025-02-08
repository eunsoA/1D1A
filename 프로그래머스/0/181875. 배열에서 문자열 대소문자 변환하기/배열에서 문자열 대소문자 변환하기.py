def solution(strArr):
    for idx, word in enumerate(strArr):
        if idx % 2:
            strArr[idx] = word.upper()
        else :
            strArr[idx] = word.lower()
    return strArr