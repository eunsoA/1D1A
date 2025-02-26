numbers = [int(input()) for _ in range(9)]  # 9개의 숫자 입력받기
max_value = max(numbers)  # 최댓값 찾기
max_index = numbers.index(max_value) + 1  # 최댓값의 위치 (1-based index)

print(max_value)
print(max_index)
