# 점수를 입력받기
score = int(input())

# 조건에 따라 등급 출력
if 90 <= score <= 100:
    print("A")
elif 80 <= score < 90:
    print("B")
elif 70 <= score < 80:
    print("C")
elif 60 <= score < 70:
    print("D")
else:
    print("F")
