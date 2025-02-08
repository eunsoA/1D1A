def solution(strArr):
    arr = []
    for word in strArr:
        if "ad" not in word : arr.append(word)
    return arr