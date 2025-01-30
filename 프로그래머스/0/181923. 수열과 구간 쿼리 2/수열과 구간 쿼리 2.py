def solution(arr, queries):
    answer = []
    for s, e, k in queries:
        numbers = [num for num in arr[s:e+1] if num > k]
        answer.append(min(numbers) if numbers else -1)
    return answer