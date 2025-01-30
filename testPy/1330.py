# 두 정수를 입력받기
A, B = map(int, input().split())

# 조건에 따라 비교 결과 출력
if A > B:
    print(">")
elif A < B:
    print("<")
else:
    print("==")