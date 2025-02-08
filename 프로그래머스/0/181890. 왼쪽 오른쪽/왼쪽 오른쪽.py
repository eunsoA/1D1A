def solution(str_list):
    if "l" in str_list and "r" in str_list:
        idxL = str_list.index("l")
        idxR = str_list.index("r")
        if idxL < idxR:
            return str_list[:idxL]
        else :
            return str_list[idxR+1:]
    elif "l" in str_list:
        return str_list[:str_list.index("l")]
    elif "r" in str_list:
        return str_list[str_list.index("r")+1:]
    else:
        return []