def solution(ineq, eq, n, m):
    if (eq == '!') : # <  or >
        if(ineq == '>') :
            return int(n>m)
        else :
            return int(n<m)
    else :  # >= or <=
        if(ineq == '>') :
            return int(n>=m)
        else :
            return int(n<=m)
    return answer