def solution(my_string):
    from collections import Counter
    
    # 알파벳 리스트 생성 (대문자 + 소문자)
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    
    # 문자열 내 문자 개수 세기
    count_dict = Counter(my_string)
    
    # 알파벳 순서대로 개수 리스트 생성
    result = [count_dict[char] if char in count_dict else 0 for char in alphabet]
    
    return result