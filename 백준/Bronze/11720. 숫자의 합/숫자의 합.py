# N 입력받기 (실제로는 사용되지 않음)
N = int(input())

# 숫자 문자열 입력받기
numbers = input()

# 각 숫자를 정수로 변환해 합 계산
result = sum(map(int, numbers))

# 결과 출력
print(result)
