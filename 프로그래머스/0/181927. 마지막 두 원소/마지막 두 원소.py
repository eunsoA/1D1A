def solution(nlist):
    nlist.append(nlist[-1]-nlist[-2] if nlist[-1] > nlist[-2] else nlist[-1]*2)
    return nlist