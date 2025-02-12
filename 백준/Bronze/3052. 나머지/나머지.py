numbers = [int(input()) for _ in range(10)]  # 10개의 숫자 입력 받기
remainders = {num % 42 for num in numbers}  # 나머지를 집합에 저장 (중복 제거)
print(len(remainders))  # 서로 다른 나머지 개수 출력
