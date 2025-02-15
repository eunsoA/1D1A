import re
def solution(myStr):
    result = list(filter(None, re.split("[abc]", myStr)))
    return result if result else ["EMPTY"]