def solution(routes):
    answer = 0
    routes.sort(key = lambda x: x[1])
    pos = -30001
    for r in routes:
        if r[0] > pos:
            pos = r[1]
            answer += 1
    return answer