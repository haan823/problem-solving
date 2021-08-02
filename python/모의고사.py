def solution(answers):
    answer = []
    max = -1
    l = [[1, 2, 3, 4, 5], [2, 1, 2, 3, 2, 4, 2, 5], [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]
    for i in range(3):
        tmp = len(l[i])
        cnt = 0
        for j, v in enumerate(answers):
            if v == l[i][j%tmp]:
                cnt += 1
        if cnt > max:
            max = cnt
            answer.clear()
            answer.append(i+1)
        elif cnt == max:
            answer.append(i+1)
    answer.sort()
    return answer