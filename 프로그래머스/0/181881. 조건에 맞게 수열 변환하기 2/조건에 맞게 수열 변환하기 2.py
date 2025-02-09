def cal(arr) :
    return [n//2 if n>=50 and n%2==0 else n*2+1 if n < 50 and n % 2 else n for n in arr]

def solution(arr):
    count = 0
    prev_arr = arr[:]
    while True :
        next_arr = cal(prev_arr)
        if next_arr == prev_arr:
            break
        prev_arr = next_arr[:]
        count += 1
    return count