def solution(array, commands):
    answer = []
    for c in commands:
        l = sorted(array[c[0]-1:c[1]])
        answer.append(l[c[2]-1])
    return answer