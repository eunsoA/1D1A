def solution(n):
    if(n%2) :
        return sum(range(1,n+1,2))  # odd
    return sum(list(i**2 for i in range(2,n+1,2))) # even