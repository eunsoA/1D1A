import re
def solution(myStr):
    result = [x for x in myStr.replace('a',' ').replace('b',' ').replace('c',' ').split() if x]
    return result if result else ["EMPTY"]