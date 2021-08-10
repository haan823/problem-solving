import math

def solution(brown, yellow):
    total = brown + yellow
    answer = []
    for i in range(3, int(math.sqrt(total)+1)):
        if total % i == 0:
            j = total // i
            if (i-2) * (j-2) == yellow:
                answer.append(i)
                answer.append(j)
                break
    return sorted(answer, reverse=True)