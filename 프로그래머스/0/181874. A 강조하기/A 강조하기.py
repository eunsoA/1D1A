def solution(myString):
    return ''.join(c.lower() if c.upper() != 'A' else c.upper() for c in myString)