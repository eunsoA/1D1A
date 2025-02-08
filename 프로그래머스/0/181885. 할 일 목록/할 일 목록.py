def solution(todo_list, finished):
    answer = []
    for idx, done in enumerate(finished):
        if not finished[idx] : answer.append(todo_list[idx])
    return answer