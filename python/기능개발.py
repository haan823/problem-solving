def solution(progresses, speeds):
    answer = []
    while len(progresses) > 0:
        cnt = 0
        for i in range(len(progresses)):
            progresses[i] += speeds[i]
        while True:
            if len(progresses) == 0:
                break
            if progresses[0] >= 100:
                progresses.pop(0)
                speeds.pop(0)
                cnt += 1
            else:
                break
        if cnt > 0:
            answer.append(cnt)
    return answer